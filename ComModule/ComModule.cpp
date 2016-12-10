#include <iostream>
#include <iomanip>
#include "ComModule.hpp"

ComModule::ComModule()
  : mq_(100), sock_(&mq_), i2c_(&mq_), appAlive_(false),
    radarTimer_(&mq_, TIMER_RADAR,
		constants::TIMER_INTERVAL_RADAR),
    opdriftTimer_(&mq_, TIMER_OPDRIFT,
		  constants::TIMER_INTERVAL_OPDRIFT),
    keepAliveTimer_(&mq_, TIMER_KEEPALIVE,
		    constants::TIMER_INTERVAL_KEEPALIVE)
{
}

ComModule::~ComModule()
{
}

void ComModule::run()
{
  pthread_create(&pt_, NULL, ComModule::staticStarter, this);
  sock_.run();
  i2c_.run();
  radarTimer_.run();
  opdriftTimer_.run();
  keepAliveTimer_.run();
}

void ComModule::join()
{
  void *exitStatus;
  pthread_join(pt_, &exitStatus);
}

void* ComModule::staticStarter(void* arg)
{
  ComModule *t = static_cast<ComModule*>(arg);
  t->comModuleThread();

  return NULL;
}

void ComModule::comModuleThread()
{
  while(true) {
    unsigned long id;
    Message* msg = mq_.receive(id);
    handleMsg(msg, id);
    delete msg;
  }
}

void ComModule::handleMsg(Message *msg, unsigned long id)
{
  switch (id) {
  case TIMER_RADAR:
    {
      handleMsgTimerRadar(msg);
      break;
    }
  case TIMER_OPDRIFT:
    {
      handleMsgTimerOpdrift(msg);
      break;
    }
  case TIMER_KEEPALIVE:
    {
      handleMsgTimerKeepalive(msg);
      break;
    }

  case RECEIVE_UDP_PACKET:
    {
      handleMsgReceiveUdpPacket(msg);
      break;
    }

  case RECEIVE_I2C_PACKET_RADAR:
    {
      handleMsgReceiveI2cPacketRadar(msg);
      break;
    }
  case RECEIVE_I2C_PACKET_OPDRIFT:
    {
      handleMsgReceiveI2cPacketOpdrift(msg);
      break;
    }
  case RECEIVE_I2C_PACKET_TEST:
    {
      handleMsgReceiveI2cPacketTest(msg);
      break;
    }

  default:
    {
      std::cout << "ComMod: Error - default" << std::endl;
      break;
    }
  }
}

// ********************
// * Message handlers *
// ********************

void ComModule::handleMsgTimerRadar(Message *msg)
{
  // Time is up: Query radar module for new data
  i2c_.send(I2CHandler::I2C_READ_RADAR);
}

void ComModule::handleMsgTimerOpdrift(Message *msg)
{
  // Time is up: Query opdrift module for status
  i2c_.send(I2CHandler::I2C_READ_OPDRIFT);
}

void ComModule::handleMsgTimerKeepalive(Message *msg)
{
  if (!appAlive_) {
    // We did not receive any UDP packets from the app
    //  since last timeout. Do somthing?

    // Not implemented yet.
  }
  appAlive_ = false;
}

void ComModule::handleMsgReceiveI2cPacketRadar(Message *msg)
{
  PacketMessage *p = static_cast<PacketMessage*>(msg);
  if (radar_.newData(p->buf_[0], p->buf_[1])) {
    // We just read some new data from the radar: Inform the app
    SocketHandler::SendUDPMessage *m
      = new SocketHandler::SendUDPMessage();
    m->buf_[0] = 'R';
    m->buf_[1] = p->buf_[0];
    m->buf_[2] = p->buf_[1];
    m->len_ = 3;
    sock_.send(SocketHandler::SEND_UDP_PACKET, m);
  }
}

void ComModule::handleMsgReceiveI2cPacketOpdrift(Message *msg)
{
  PacketMessage *p = static_cast<PacketMessage*>(msg);
  // Check length, SOP, EOP and if data is new
  if (p->len_ == constants::I2C_OPDRIFT_LENGTH &&
      p->buf_[0] == constants::I2C_SOP &&
      p->buf_[2] == constants::I2C_EOP &&
      opdrift_.newData(p->buf_[0])) {
    // Read some new data from the opdrift system: Inform the app
    SocketHandler::SendUDPMessage *m
      = new SocketHandler::SendUDPMessage();
    m->buf_[0] = 'O'; // capital o
    m->buf_[1] = p->buf_[1];
    m->len_ = 2;
    sock_.send(SocketHandler::SEND_UDP_PACKET, m);
  }
}

void ComModule::handleMsgReceiveI2cPacketTest(Message *msg)
{
  PacketMessage *p = static_cast<PacketMessage*>(msg);
  std::cout << "Test returned status: "
	    << std::setbase(16) << (int)p->buf_[1] << std::endl;
}

void ComModule::handleMsgReceiveUdpPacket(Message *msg)
{
  // Got UDP packet from the Wifi module
  appAlive_ = true;
  PacketMessage *in = static_cast<PacketMessage*>(msg);

  if (in->len_ < 2) {
    // Error
    return;
  }

  std::cout << "ComMod got msg: " << in->buf_[0]
	    << std::hex << (int) in->buf_[1] << std::endl;

  // Message should be ok, prepare out-message
  I2CHandler::SendI2CMessage *out = new I2CHandler::SendI2CMessage();
  int outId;
  
  switch (in->buf_[0]) {
  case 'T': // Test
    {
      outId = I2CHandler::SEND_I2C_PACKET_TEST;
      out->buf_[0] = 0x01;
      out->buf_[1] = (in->buf_[1] - '0');
      out->buf_[2] = 0x17;
      out->len_ = 3;
      i2c_.send(outId, out);
      break;
    }

  case 'I': // Inflate
    {
      outId = I2CHandler::SEND_I2C_PACKET_OPDRIFT;
      out->buf_[0] = constants::I2C_SOP;
      out->buf_[1] = in->buf_[1];
      out->buf_[2] = constants::I2C_EOP;
      out->len_ = 3;
      i2c_.send(outId, out);
      break;
    }
  case 'R': // Strafe
    {
      outId = I2CHandler::SEND_I2C_PACKET_REGULATOR;
      out->len_ = regulator_.updateAngleStrafe(in->buf_[1], out->buf_);
      i2c_.send(outId, out);
      break;
    }
  case 'S': // Steer
    {
      outId = I2CHandler::SEND_I2C_PACKET_REGULATOR;
      out->len_ = regulator_.updateAngleSteer(in->buf_[1], out->buf_);
      i2c_.send(outId, out);
      break;
    }
  case 'P': // Propulsion
    {
      outId = I2CHandler::SEND_I2C_PACKET_REGULATOR;
      out->len_ = regulator_.updateSpeed(in->buf_[1], out->buf_);
      i2c_.send(outId, out);
      break;
    }

  default:
    {
      break;
    }
  }
}

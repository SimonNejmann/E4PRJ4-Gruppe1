#include <iostream>
#include "I2CHandler.hpp"
#include "ComModule.hpp"

I2CHandler::I2CHandler(MsgQueue *partnerMq)
  : mq_(10), partnerMq_(partnerMq), i2c_(constants::I2C_DEVICE)
{}

I2CHandler::~I2CHandler()
{}

void I2CHandler::send(unsigned long id, Message* msg)
{
  mq_.send(id, msg);
}
  
void I2CHandler::runThread()
{
  unsigned long id;
  while(true) {
    Message *msg = mq_.receive(id);
    handleMsg(msg, id);
    delete msg;
  }
}

void I2CHandler::handleMsg(Message *msg, unsigned long id)
{
  switch(id) {
  case I2C_READ_RADAR:
    {
      ComModule::PacketMessage *m = new ComModule::PacketMessage();
      m->len_ = i2c_.receive(constants::I2C_RADAR_ADDR, m->buf_,
			     constants::I2C_RADAR_LENGTH);
      if (m->len_ < 0) {
	// Read error, discard message
	std::cout << "I2C_H: Read error from radar" << std::endl;
	delete m;
      } else {
	// Read ok, send
	partnerMq_->send(ComModule::RECEIVE_I2C_PACKET_RADAR, m);
      }
      break;
    }
  case I2C_READ_OPDRIFT:
    {
      ComModule::PacketMessage *m = new ComModule::PacketMessage();
      m->len_ = i2c_.receive(constants::I2C_OPDRIFT_ADDR, m->buf_,
			     constants::I2C_OPDRIFT_LENGTH);
      if (m->len_ < 0) {
	// Read error, discard message
	std::cout << "I2C_H: Read error from opdrift" << std::endl;
	delete m;
      } else {
	// Read ok, send
	partnerMq_->send(ComModule::RECEIVE_I2C_PACKET_OPDRIFT, m);
      }
      break;
    }
  case SEND_I2C_PACKET_OPDRIFT:
    {
      SendI2CMessage *sm = static_cast<SendI2CMessage*>(msg);
      i2c_.send(constants::I2C_OPDRIFT_ADDR, sm->buf_, sm->len_);
      break;
    }
  case SEND_I2C_PACKET_REGULATOR:
    {
      SendI2CMessage *sm = static_cast<SendI2CMessage*>(msg);
      /*
      std::cout << "I2C_H: Sending to regulator: 0x"
		<< std::hex << (int) sm->buf_[0] << (int) sm->buf_[1]
		<< (int) sm->buf_[2] << std::endl;
      */
      i2c_.send(constants::I2C_REGULATOR_ADDR, sm->buf_, sm->len_);
      break;
    }
  case SEND_I2C_PACKET_TEST:
    {
      SendI2CMessage *sm = static_cast<SendI2CMessage*>(msg);
      i2c_.send(constants::I2C_TEST_ADDR, sm->buf_, sm->len_);

      ComModule::PacketMessage *m = new ComModule::PacketMessage();
      m->len_ = i2c_.receive(constants::I2C_TEST_ADDR, m->buf_,
			     constants::I2C_TEST_LENGTH);
      if (m->len_ < 0) {
	std::cout << "I2C_H: Read error from test" << std::endl;
	// Read error, discard message
	delete m;
      } else {
	// Read ok, send
	partnerMq_->send(ComModule::RECEIVE_I2C_PACKET_TEST, m);
      }
      break;
    }
  default:
    // Error!
    return;
  }
}

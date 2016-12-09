#include <iostream>
#include "I2CHandler.hpp"
#include "ComModule.hpp"

I2CHandler::I2CHandler(MsgQueue *partnerMq)
  : mq_(10), partnerMq_(partnerMq), i2c_(constants::I2C_DEVICE)
{}

I2CHandler::~I2CHandler()
{}
  
void I2CHandler::run()
{
  pthread_t pt;
  pthread_create(&pt, NULL, I2CHandler::staticStarter, this);
}

void I2CHandler::send(unsigned long id, Message* msg)
{
  mq_.send(id, msg);
}
  
void* I2CHandler::staticStarter(void* arg)
{
  I2CHandler *t = static_cast<I2CHandler*>(arg);
  t->i2cHandlerThread();

  return NULL;
}

void I2CHandler::i2cHandlerThread()
{
  while(true) {
    unsigned long id;
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
      partnerMq_->send(ComModule::RECEIVE_I2C_PACKET_RADAR, m);
      break;
    }
  case I2C_READ_OPDRIFT:
    {
      ComModule::PacketMessage *m = new ComModule::PacketMessage();
      m->len_ = i2c_.receive(constants::I2C_OPDRIFT_ADDR, m->buf_,
			     constants::I2C_OPDRIFT_LENGTH);
      partnerMq_->send(ComModule::RECEIVE_I2C_PACKET_OPDRIFT, m);
      break;
    }
  case SEND_I2C_PACKET_OPDRIFT:
    {
      SendI2CMessage *sm = static_cast<SendI2CMessage*>(msg);
      i2c_.send(constants::I2C_OPDRIFT_ADDR, sm->buf_, sm->len_);
      break;
    }
  case SEND_I2C_PACKET_CONTROLLER:
    {
      SendI2CMessage *sm = static_cast<SendI2CMessage*>(msg);
      i2c_.send(constants::I2C_CONTROLLER_ADDR, sm->buf_, sm->len_);
      break;
    }
  case SEND_I2C_PACKET_TEST:
    {
      SendI2CMessage *sm = static_cast<SendI2CMessage*>(msg);
      std::cout << "I2C got test msg: " << sm->buf_ << std::endl;
      i2c_.send(constants::I2C_TEST_ADDR, sm->buf_, sm->len_);

      ComModule::PacketMessage *m = new ComModule::PacketMessage();
      m->len_ = i2c_.receive(constants::I2C_TEST_ADDR, m->buf_,
			     constants::I2C_TEST_LENGTH);
      partnerMq_->send(ComModule::RECEIVE_I2C_PACKET_TEST, m);
      break;
    }
  default:
    // Error!
    return;
  }
}

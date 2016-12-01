#include <iostream>
#include "ComModule.hpp"

ComModule::ComModule()
  : mq_(10), sock_(&mq_), i2c_(&mq_)
{
}

ComModule::~ComModule()
{
}

void ComModule::run()
{
  pthread_create(&pt_, NULL, ComModule::staticStarter, this);
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
  sock_.run();
  i2c_.run();
  
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
    case GOT_PACKET: 
      {
        PacketMessage *p = static_cast<PacketMessage*>(msg);

	char val;
	switch (p->buf_[0]) {
	case '0':
	  val = 0;
	  break;
	case '1':
	  val = 1;
	  break;
	case '2':
	  val = 2;
	  break;
	case '3':
	  val = 3;
	  break;
	default:
	  val = -1;
	  break;
	}

	I2CHandler::SendI2CMessage *iMsg
	  = new I2CHandler::SendI2CMessage();

	iMsg->addr_ = 0x08;
	iMsg->buf_[0] = 0x01;
	iMsg->buf_[1] = val;
	iMsg->buf_[2] = 0x17;
	iMsg->len_ = 3;
	i2c_.send(I2CHandler::SEND_I2C_MSG, iMsg);
	
        break;
      }
    default:
      break;
  }
}

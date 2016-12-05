#include <iostream>
#include "ComModule.hpp"

ComModule::ComModule()
  : mq_(10), sock_(&mq_), i2c_(&mq_), s_(&sock_)
{
}

ComModule::~ComModule()
{
}

void ComModule::run()
{
  pthread_create(&pt_, NULL, ComModule::staticStarter, this);
  pthread_t st;
  pthread_create(&st, NULL, Sender::run, &s_);
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
  std::cout << "ComMod running" << std::endl;
  sock_.run();
  
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
        std::cout << "Got Packet, length: " << p->len_
                  << ", msg: " << p->buf_ << std::endl;
        break;
      }
    default:
      break;
  }
}

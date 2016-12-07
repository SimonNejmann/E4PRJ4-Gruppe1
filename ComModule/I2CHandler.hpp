#ifndef I2C_HANDLER_HPP_
#define I2C_HANDLER_HPP_

#include "MsgQueue.hpp"
#include "I2C.hpp"

class I2CHandler
{
public:
  I2CHandler(MsgQueue *partnerMq)
    : mq_(10), partnerMq_(partnerMq), i2c_(constants::I2C_DEVICE) {}
  ~I2CHandler() {}
  
  void run()
  {
    pthread_t pt;
    pthread_create(&pt, NULL, I2CHandler::staticStarter, this);
  }

  void send(unsigned long id, Message* msg = NULL)
  {
    mq_.send(id, msg);
  }

  enum { SEND_I2C_MSG };

  struct SendI2CMessage : public Message {
    int addr_;
    char buf_[constants::BUFFER_SIZE];
    int len_;
  };

private:
  MsgQueue mq_;
  I2C i2c_;

  MsgQueue *partnerMq_;
  
  static void* staticStarter(void* arg)
  {
    I2CHandler *t = static_cast<I2CHandler*>(arg);
    t->i2cHandlerThread();

    return NULL;
  }

  void i2cHandlerThread()
  {
    while(true) {
      unsigned long id;
      Message *msg = mq_.receive(id);
      handleMsg(msg, id);
      delete msg;
    }
  }

  void handleMsg(Message *msg, unsigned long id)
  {
    switch(id) {
    case SEND_I2C_MSG:
      {
	SendI2CMessage *sm = static_cast<SendI2CMessage*>(msg);
        i2c_.send(sm->addr_, sm->buf_, sm->len_);
        break;
      }
    default:
      // Error!
      return;
    }
  }
};

#endif // I2C_HANDLER_HPP_

#ifndef I2C_HANDLER_HPP_
#define I2C_HANDLER_HPP_

#include "MsgQueue.hpp"
#include "I2C.hpp"

class I2CHandler
{
public:
  I2CHandler(MsgQueue *partnerMq) : mq_(10), partnerMq_(partnerMq) {}
  ~I2CHandler() {}
  
  void run()
  {
    pthread_t pt;
    pthread_create(&pt, NULL, I2CHandler::staticStarter, this);
  }

private:
  MsgQueue mq_;
  I2C com_;

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
    }
  }
  
};

#endif // I2C_HANDLER_HPP_

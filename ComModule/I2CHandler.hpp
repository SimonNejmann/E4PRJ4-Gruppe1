#ifndef I2C_HANDLER_HPP_
#define I2C_HANDLER_HPP_

#include "constants.hpp"
#include "MsgQueue.hpp"
#include "I2C.hpp"

class I2CHandler
{
public:
  I2CHandler(MsgQueue *partnerMq);
  ~I2CHandler();
  
  void run();
  void send(unsigned long id, Message* msg = NULL);

  enum { I2C_READ_RADAR, I2C_READ_OPDRIFT,
	 SEND_I2C_PACKET_OPDRIFT, SEND_I2C_PACKET_CONTROLLER,
	 SEND_I2C_PACKET_TEST };

  struct SendI2CMessage : public Message {
    char buf_[constants::BUFFER_SIZE];
    int len_;
  };

private:
  MsgQueue mq_;
  I2C i2c_;

  MsgQueue *partnerMq_;
  
  static void* staticStarter(void* arg);
  void i2cHandlerThread();
  void handleMsg(Message *msg, unsigned long id);
};

#endif // I2C_HANDLER_HPP_

#ifndef I2C_HANDLER_HPP_
#define I2C_HANDLER_HPP_

#include "constants.hpp"
#include "MsgQueue.hpp"
#include "I2C.hpp"
#include "Thread.hpp"

class I2CHandler : public Thread
{
public:
  I2CHandler(MsgQueue *partnerMq);
  ~I2CHandler();
  
  void send(unsigned long id, Message* msg = NULL);

  enum { I2C_READ_RADAR, I2C_READ_OPDRIFT,
	 SEND_I2C_PACKET_OPDRIFT, SEND_I2C_PACKET_REGULATOR,
	 SEND_I2C_PACKET_TEST };

  struct SendI2CMessage : public Message {
    char buf_[constants::BUFFER_SIZE];
    int len_;
  };

private:
  MsgQueue mq_;
  MsgQueue *partnerMq_;
  
  I2C i2c_;

  void runThread();
  void handleMsg(Message *msg, unsigned long id);
};

#endif // I2C_HANDLER_HPP_

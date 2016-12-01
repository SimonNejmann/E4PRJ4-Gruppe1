#ifndef COM_MODULE_HPP_
#define COM_MODULE_HPP_

#include "SocketHandler.hpp"
#include "I2CHandler.hpp"
#include "constants.hpp"

class ComModule
{
public:
  ComModule();
  ~ComModule();
  
  void run();
  void join();
  
  enum { GOT_PACKET };

  struct PacketMessage : public Message {
    char buf_[constants::BUFFER_SIZE];
    int len_;
  };

private:
  pthread_t pt_;
  MsgQueue mq_;
  SocketHandler sock_;
  I2CHandler i2c_;
  
  static void* staticStarter(void* arg);
  void comModuleThread();
  void handleMsg(Message *msg, unsigned long id);

};

#endif // COM_MODULE_HPP_

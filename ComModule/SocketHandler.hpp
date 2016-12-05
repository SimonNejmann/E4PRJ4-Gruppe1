#ifndef SOCKETHANDLER_HPP_
#define SOCKETHANDLER_HPP_

#include "MsgQueuePipe.hpp"
#include "UDPSocket.hpp"
#include "constants.hpp"

class SocketHandler
{
public:
  SocketHandler(MsgQueue *comModMq);
  ~SocketHandler();
  
  void run();
  void send(unsigned long id, Message* msg = NULL);

  enum { SEND_PACKET, POINT_MSG };

  struct SendMessage : public Message {
    char buf_[constants::BUFFER_SIZE];
    int len_;
  };

private:
  MsgQueuePipe mq_;
  MsgQueue *comModMq_;
  
  UDPSocket sock_;
  char buf_[constants::BUFFER_SIZE];
  
  static void* staticStarter(void* arg);
  void sockethandlerThread();
  void handleMsg(Message *msg, unsigned long id);
};

#endif //SOCKETHANDLER_HPP_

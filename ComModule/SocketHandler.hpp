#ifndef SOCKETHANDLER_HPP_
#define SOCKETHANDLER_HPP_

#include "MsgQueuePipe.hpp"
#include "UDPSocket.hpp"
#include "constants.hpp"
#include "Thread.hpp"

class SocketHandler : public Thread
{
public:
  SocketHandler(MsgQueue *comModMq);
  ~SocketHandler();
  
  void send(unsigned long id, Message* msg = NULL);

  enum { SEND_UDP_PACKET };

  struct SendUDPMessage : public Message {
    char buf_[constants::BUFFER_SIZE];
    int len_;
  };

private:
  MsgQueuePipe mq_;
  MsgQueue *comModMq_;
  
  UDPSocket sock_;
  
  void runThread();
  void handleMsg(Message *msg, unsigned long id);
};

#endif //SOCKETHANDLER_HPP_

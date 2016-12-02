#ifndef SOCKETHANDLER_HPP_
#define SOCKETHANDLER_HPP_

#include "MsgQueuePipe.hpp"
#include "UDPSocket.hpp"

class SocketHandler
{
public:
  SocketHandler();
  ~SocketHandler();
  
  static void* run(void* arg);
  void send(unsigned long id, Message* msg = NULL);

  enum MsgType { POINT_MSG };
  
private:
  static const int BUFFER_SIZE = 1024;
  
  MsgQueuePipe mq_;
  UDPSocket sock_;
  char buf_[BUFFER_SIZE];
  
  void sockethandlerThread();
  void handleMsg(Message *msg, unsigned long id);
};

#endif //SOCKETHANDLER_HPP_

#include <iostream>
#include <sys/select.h>
#include "SocketHandler.hpp"
#include "util.hpp"
#include "Point.hpp"

SocketHandler::SocketHandler()
  : mq_(5), sock_(8575)
{
}

SocketHandler::~SocketHandler()
{
}

void* SocketHandler::run(void* arg)
{
  SocketHandler *s = static_cast<SocketHandler*>(arg);
  s->sockethandlerThread();

  return NULL;
}

void SocketHandler::send(unsigned long id, Message* msg)
{
  mq_.send(id, msg);
}
  
void SocketHandler::sockethandlerThread()
{
  unsigned long id;
  fd_set watch_set, result_set;
  int mq_fd = mq_.getReceiveFD();
  int sock_fd = sock_.getFD();

  int fdLimit = util::max(mq_fd, sock_fd) +1;
    
  FD_ZERO(&watch_set);
  FD_SET(mq_fd, &watch_set);
  FD_SET(sock_fd, &watch_set);
    
  while(true) {
    result_set = watch_set;
    select(fdLimit, &result_set, NULL, NULL, NULL);
      
    if (FD_ISSET(mq_fd, &result_set)) {
      // Message in message queue
      Message *msg = mq_.receive(id);
      handleMsg(msg, id);
      delete msg;
        
    } else if(FD_ISSET(sock_fd, &result_set)) {
      // Packet incomming on socket
      int n = sock_.receive(buf_, BUFFER_SIZE);
      buf_[n] = '\0';
      std::cout << "Got packet: " << n << " bytes: " << buf_ << std::endl;
        
    } else {
      std::cout << "Error" << std::endl;
    }
  }
}

void SocketHandler::handleMsg(Message *msg, unsigned long id)
{
  Point *p;
  // no state, only switch on id
  switch(id) {
    case POINT_MSG:
      p = dynamic_cast<Point*>(msg);
      std::cout << "Got point: " << p->x << ", " << p->y << ", "
                << p->z << std::endl;
      break;
          
    default:
      // Error!
      return;
  }
}

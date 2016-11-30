#ifndef _RECEIVER_HPP_
#define _RECEIVER_HPP_

#include <iostream>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "MsgQueuePipe.hpp"
#include "Point.hpp"

class Receiver
{
public:
  Receiver()
    : mq_(5)
  {
    sock_=socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port=htons(8725);
    bind(sock_, reinterpret_cast<struct sockaddr*>(&server), sizeof(server));
  }
  ~Receiver()
  {
  }
  
  static void* run(void* arg)
  {
    Receiver *s = static_cast<Receiver*>(arg);
    s->receiverThread();

    return NULL;
  }

  void send(unsigned long id, Message* msg = NULL)
  {
    mq_.send(id, msg);
  }

  enum MsgType { POINT_MSG };
  
private:
  MsgQueuePipe mq_;
  int sock_;
  char buf_[1024];
  
  void receiverThread()
  {
    unsigned long id;
    fd_set watch_set, read_set;
    int mqFD = mq_.getReceiveFD();

    int fdLimit = (mqFD > sock_) ? mqFD+1 : sock_+1;
    
    FD_ZERO(&watch_set);
    FD_SET(mqFD, &watch_set);
    FD_SET(sock_, &watch_set);
    
    while(true) {
      read_set = watch_set;
      select(fdLimit, &read_set, NULL, NULL, NULL);
      if (FD_ISSET(mqFD, &read_set)) {
        Message *msg = mq_.receive(id);
        handleMsg(msg, id);
        delete msg;
        
      } else if(FD_ISSET(sock_, &read_set)) {
        int n = recvfrom(sock_, buf_, 1024, 0, NULL, NULL);
        buf_[n] = '\0';
        std::cout << "Got packet: " << buf_ << std::endl;
        
      } else {
        std::cout << "Error" << std::endl;
      }
    }
  }

  void handleMsg(Message *msg, unsigned long id)
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
};

#endif //_RECEIVER_HPP_

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
  {
    mq = new MsgQueuePipe(5);

    sock=socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port=htons(8725);
    bind(sock, reinterpret_cast<struct sockaddr*>(&server), sizeof(server));
  }
  ~Receiver()
  {
    delete mq;
  }
  
  static void* run(void* arg)
  {
    Receiver *s = static_cast<Receiver*>(arg);
    s->receiverThread();

    return NULL;
  }

  void send(unsigned long id, Message* msg = NULL)
  {
    mq->send(id, msg);
  }

  enum MsgType { POINT_MSG };
  
private:
  MsgQueuePipe *mq;
  int sock;
  char buf[1024];
  
  void receiverThread()
  {
    unsigned long id;
    fd_set watch_set, read_set;
    int mqFD = mq->getReceiveFD();

    int fdLimit = (mqFD > sock) ? mqFD+1 : sock+1;
    
    FD_ZERO(&watch_set);
    FD_SET(mqFD, &watch_set);
    FD_SET(sock, &watch_set);
    
    while(true) {
      read_set = watch_set;
      select(fdLimit, &read_set, NULL, NULL, NULL);
      if (FD_ISSET(mqFD, &read_set)) {
        Message *msg = mq->receive(id);
        handleMsg(msg, id);
        delete msg;
        
      } else if(FD_ISSET(sock, &read_set)) {
        int n = recvfrom(sock, buf, 1024, 0, NULL, NULL);
        buf[n] = '\0';
        std::cout << "Got packet: " << buf << std::endl;
        
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

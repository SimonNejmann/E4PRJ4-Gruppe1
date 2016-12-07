#ifndef SENDER_HPP_
#define SENDER_HPP_

#include <iostream>
#include "util.hpp"
#include "Point.hpp"
#include "SocketHandler.hpp"

class Sender
{
public:
  Sender(SocketHandler *r) : receiver(r) {}
  ~Sender() {}
  
  static void* run(void* arg)
  {
    Sender *s = static_cast<Sender*>(arg);
    s->senderThread();

    return NULL;
  }
  
private:
  SocketHandler *receiver;

  Point* newPoint()
  {
    Point *p = new Point;
    p->x = util::randVal(0,100);
    p->y = util::randVal(0,100);
    p->z = util::randVal(0,100);
  }
  
  void senderThread()
  {
    Point *p;
    while(true) {
      util::randSleep(1000, 1001);
      p = newPoint();
      std::cout << "Sender sending msg" << std::endl;
      receiver->send(SocketHandler::POINT_MSG, p);
    }
  }
};

#endif // SENDER_HPP_

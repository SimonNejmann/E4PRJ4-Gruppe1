#ifndef _SENDER_HPP_
#define _SENDER_HPP_

#include <iostream>
#include "util.hpp"
#include "Point.hpp"
#include "Receiver.hpp"

class Sender
{
public:
  Sender(Receiver *r) : receiver(r) {}
  ~Sender() {}
  
  static void* run(void* arg)
  {
    Sender *s = static_cast<Sender*>(arg);
    s->senderThread();

    return NULL;
  }
  
private:
  Receiver *receiver;

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
      receiver->send(Receiver::POINT_MSG, p);
    }
  }
};

#endif //_SENDER_HPP_

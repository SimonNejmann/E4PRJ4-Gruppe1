#ifndef TIMERTHREAD_HPP_
#define TIMERTHREAD_HPP_

#include <pthread.h>
#include "MsgQueue.hpp"
#include "util.hpp"

class TimerThread
{
public:
  TimerThread(MsgQueue *r, unsigned long id, int timeout)
    : receiver_(r), msgId_(id), timeout_(timeout) {}
  ~TimerThread() {}
  
  static void* run(void* arg)
  {
    TimerThread *t = static_cast<TimerThread*>(arg);
    t->timerThread();

    return NULL;
  }
  
private:
  MsgQueue *receiver_;
  unsigned long msgId_;
  int timeout_;
  
  void timerThread()
  {
    while(true) {
      util::randSleep(timeout_, timeout_);
      receiver_->send(msgId_);
    }
  }
};

#endif // TIMERTHREAD_HPP_

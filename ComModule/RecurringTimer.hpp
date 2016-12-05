#ifndef RECURRINGTIMER_HPP_
#define RECURRINGTIMER_HPP_

#include <pthread.h>
#include "MsgQueue.hpp"
#include "util.hpp"

class RecurringTimer
{
public:
  RecurringTimer(MsgQueue *r, unsigned long id, int timeout)
    : receiver_(r), msgId_(id), timeout_(timeout) {}
  ~RecurringTimer() {}
  
  void run()
  {
    pthread_t pt;
    pthread_create(&pt, NULL, RecurringTimer::staticStarter, this);
  }

private:
  MsgQueue *receiver_;
  unsigned long msgId_;
  int timeout_;
  
  static void* staticStarter(void* arg)
  {
    RecurringTimer *t = static_cast<RecurringTimer*>(arg);
    t->recurringTimerThread();

    return NULL;
  }

  void recurringTimerThread()
  {
    while(true) {
      util::randSleep(timeout_, timeout_);
      receiver_->send(msgId_);
    }
  }
};

#endif // RECURRINGTIMER_HPP_

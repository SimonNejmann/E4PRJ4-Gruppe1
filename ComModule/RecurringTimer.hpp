#ifndef RECURRINGTIMER_HPP_
#define RECURRINGTIMER_HPP_

#include "Thread.hpp"
#include "MsgQueue.hpp"
#include "util.hpp"

class RecurringTimer : public Thread
{
public:
  RecurringTimer(MsgQueue *r, unsigned long id, int timeout)
    : receiver_(r), msgId_(id), timeout_(timeout) {}
  ~RecurringTimer() {}
  
private:
  MsgQueue *receiver_;
  unsigned long msgId_;
  int timeout_;
  
  void runThread()
  {
    while(true) {
      util::randSleep(timeout_, timeout_);
      receiver_->send(msgId_);
    }
  }
};

#endif // RECURRINGTIMER_HPP_

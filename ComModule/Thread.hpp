#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <pthread.h>

class Thread
{
public:
  Thread() {}
  ~Thread() {}
  
  void run()
  {
    pthread_create(&pt_, NULL, Thread::staticStarter, this);
  }

  void join()
  {
    void *exitStatus;
    pthread_join(pt_, &exitStatus);
  }

private:
  pthread_t pt_;

  static void* staticStarter(void* arg)
  {
    Thread *t = static_cast<Thread*>(arg);
    t->runThread();

    return NULL;
  }

  virtual void runThread() = 0;
};

#endif // THREAD_HPP_

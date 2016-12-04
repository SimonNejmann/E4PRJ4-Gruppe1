#ifndef SCOPED_LOCKER_HPP_
#define SCOPED_LOCKER_HPP_

#include <pthread.h>

class ScopedLocker 
{
public:
  ScopedLocker(pthread_mutex_t* mut) : myMutex_(mut)
  {
    pthread_mutex_lock(myMutex_);
  }
  
  ~ScopedLocker() 
  {
    pthread_mutex_unlock(myMutex_);
  }
private:
  pthread_mutex_t* myMutex_;
};

#endif // SCOPED_LOCKER_HPP_

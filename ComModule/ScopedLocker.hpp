#ifndef _SCOPED_LOCKER_HPP_
#define _SCOPED_LOCKER_HPP_

#include <pthread.h>

class ScopedLocker 
{
public:
  ScopedLocker(pthread_mutex_t* mut) : myMutex(mut)
  {
    pthread_mutex_lock(myMutex);
  }
  
  ~ScopedLocker() 
  {
    pthread_mutex_unlock(myMutex);
  }
private:
  pthread_mutex_t* myMutex;
};

#endif // _SCOPED_LOCKER_HPP_

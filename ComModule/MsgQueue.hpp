#ifndef _MSGQUEUE_HPP_
#define _MSGQUEUE_HPP_

#include <queue>
#include <pthread.h>
#include "Message.hpp"

class MsgQueue
{
public:
  MsgQueue(unsigned long maxSize);
  virtual void send(unsigned long id, Message* msg = NULL);
  virtual Message* receive(unsigned long& id);
  virtual ~MsgQueue();
protected:
  pthread_mutex_t mut;
  pthread_cond_t cond;
  const unsigned long maxSize;

  struct item 
  {
    unsigned long id;
    Message *msg;
  };
  std::queue<struct item*> list;
};

#endif //_MSGQUEUE_HPP_

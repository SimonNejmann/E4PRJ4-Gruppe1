#ifndef MSGQUEUE_HPP_
#define MSGQUEUE_HPP_

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

private:
  pthread_mutex_t mut_;
  pthread_cond_t cond_;
  const unsigned long maxSize_;

  struct Item 
  {
    Item(unsigned long id, Message *msg): id_(id), msg_(msg) {}
    unsigned long id_;
    Message *msg_;
  };
  std::queue<Item> list_;
};

#endif // MSGQUEUE_HPP_

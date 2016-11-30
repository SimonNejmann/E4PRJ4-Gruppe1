#include "MsgQueue.hpp"
#include "ScopedLocker.hpp"

MsgQueue::MsgQueue(unsigned long maxSize) : maxSize_(maxSize)
{
  pthread_mutex_init(&mut_, NULL);
  pthread_cond_init(&cond_, NULL);
}

MsgQueue::~MsgQueue()
{
  pthread_mutex_lock(&mut_);
  while (!list_.empty()) {
    if (list_.front().msg_)
      delete list_.front().msg_;
    list_.pop();
  }
  pthread_mutex_unlock(&mut_);
  pthread_mutex_destroy(&mut_);
  pthread_cond_destroy(&cond_);
}

void MsgQueue::send(unsigned long id, Message* msg)
{
  ScopedLocker lock(&mut_);
  // While queue is full: Wait
  while (list_.size() >= maxSize_)
    pthread_cond_wait(&cond_, &mut_);

  // Queue got room
  list_.push(Item(id, msg));
  // Signal new item
  pthread_cond_broadcast(&cond_);
  // ScopedLocker will unlock
}

Message* MsgQueue::receive(unsigned long& id)
{
  ScopedLocker lock(&mut_);
  // While queue is empty: Wait
  while (list_.empty())
    pthread_cond_wait(&cond_, &mut_);
  // Queue not empty
  Item it = list_.front();
  list_.pop();
  // Signal space in queue
  pthread_cond_signal(&cond_);

  id = it.id_;
  return it.msg_;
  // ScopedLocker will unlock
}

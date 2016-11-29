#include "MsgQueue.hpp"
#include "ScopedLocker.hpp"

MsgQueue::MsgQueue(unsigned long maxSize) : maxSize(maxSize)
{
  pthread_mutex_init(&mut, NULL);
  pthread_cond_init(&cond, NULL);
}

MsgQueue::~MsgQueue()
{
  pthread_mutex_lock(&mut);
  while (!list.empty()) {
    struct item *it = list.front();
    list.pop();
    if (it->msg)
      delete it->msg;
    delete it;
  }
  pthread_mutex_unlock(&mut);
  pthread_mutex_destroy(&mut);
  pthread_cond_destroy(&cond);
}

void MsgQueue::send(unsigned long id, Message* msg)
{
  struct item *it = new struct item;
  it->id = id;
  it->msg = msg;

  ScopedLocker lock(&mut);
  // While queue is full: Wait
  while (list.size() >= maxSize)
    pthread_cond_wait(&cond, &mut);

  // Queue got room
  list.push(it);
  // Signal new item
  pthread_cond_broadcast(&cond);
  // ScopedLocker will unlock
}

Message* MsgQueue::receive(unsigned long& id)
{
  ScopedLocker lock(&mut);
  // While queue is empty: Wait
  while (list.empty())
    pthread_cond_wait(&cond, &mut);
  // Queue not empty
  struct item *it = list.front();
  list.pop();
  id = it->id;
  Message *msg = it->msg;
  delete it;
  // Signal space in queue
  pthread_cond_signal(&cond);
  return msg;
  // ScopedLocker will unlock
}

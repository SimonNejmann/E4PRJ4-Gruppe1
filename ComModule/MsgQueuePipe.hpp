#ifndef _MSGQUEUEPIPE_HPP_
#define _MSGQUEUEPIPE_HPP_

#include <queue>
#include <pthread.h>
#include "MsgQueue.hpp"
#include "Message.hpp"

class MsgQueuePipe : public MsgQueue
{
public:
  MsgQueuePipe(unsigned long maxSize);
  virtual void send(unsigned long id, Message* msg = NULL);
  virtual Message* receive(unsigned long& id);
  virtual ~MsgQueuePipe();
  bool empty();
  int getReceiveFD();
  
protected:
  int pipefd[2];
  pthread_mutex_t pipeMut;
};

#endif //_MSGQUEUEPIPE_HPP_

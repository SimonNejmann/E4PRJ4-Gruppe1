#include <unistd.h>
#include <stdio.h>
#include "MsgQueuePipe.hpp"
#include "ScopedLocker.hpp"

MsgQueuePipe::MsgQueuePipe(unsigned long maxSize) : MsgQueue(maxSize)
{
  pthread_mutex_init(&pipeMut_, NULL);
  if (pipe(pipefd_) < 0) {
    // Error
    perror(NULL);
  }
}

MsgQueuePipe::~MsgQueuePipe()
{
  close(pipefd_[0]);
  close(pipefd_[1]);  
  pthread_mutex_destroy(&pipeMut_);
}

void MsgQueuePipe::send(unsigned long id, Message* msg)
{
  MsgQueue::send(id, msg);
  ScopedLocker lock(&pipeMut_);
  char c = '1';
  if (write(pipefd_[1], &c, 1) < 0) {
    // Error
    perror(NULL);
  }
}

Message* MsgQueuePipe::receive(unsigned long& id)
{
  Message *msg = MsgQueue::receive(id);
  ScopedLocker lock(&pipeMut_);
  char c;
  if (read(pipefd_[0], &c, 1) < 0) {
    // Error
    perror(NULL);
  }
  return msg;
}

int MsgQueuePipe::getReceiveFD()
{
  return pipefd_[0];
}

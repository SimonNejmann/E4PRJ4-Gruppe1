#include <unistd.h>
#include "MsgQueuePipe.hpp"
#include "ScopedLocker.hpp"

MsgQueuePipe::MsgQueuePipe(unsigned long maxSize) : MsgQueue(maxSize)
{
  pthread_mutex_init(&pipeMut, NULL);
  pipe(pipefd);
}

MsgQueuePipe::~MsgQueuePipe()
{
  close(pipefd[0]);
  close(pipefd[1]);  
  pthread_mutex_destroy(&pipeMut);
}

void MsgQueuePipe::send(unsigned long id, Message* msg)
{
  MsgQueue::send(id, msg);
  ScopedLocker lock(&pipeMut);
  char c = '1';
  write(pipefd[1], &c, 1);
}

Message* MsgQueuePipe::receive(unsigned long& id)
{
  Message *msg = MsgQueue::receive(id);
  ScopedLocker lock(&pipeMut);
  char c;
  read(pipefd[0], &c, 1);
  return msg;
}

bool MsgQueuePipe::empty()
{
  return list.empty();
}

int MsgQueuePipe::getReceiveFD()
{
  return pipefd[0];
}

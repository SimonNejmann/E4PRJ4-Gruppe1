#include <iostream>
#include "Sender.hpp"
#include "SocketHandler.hpp"
#include "TimerThread.hpp"

int main()
{
  SocketHandler r;
  Sender s(&r);

  pthread_t rT, sT;

  pthread_create(&rT, NULL, SocketHandler::run, &r);
  pthread_create(&sT, NULL, Sender::run, &s);

  void *exitStatus;
  pthread_join(rT, &exitStatus);
  pthread_join(sT, &exitStatus);

  return 0;
}

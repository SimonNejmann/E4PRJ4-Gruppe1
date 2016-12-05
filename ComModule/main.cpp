#include <pthread.h>
#include "SocketHandler.hpp"
#include "RecurringTimer.hpp"
#include "ComModule.hpp"

int main()
{
  ComModule c;
  c.run();
  int i = 0;
  pthread_exit(&i);
  

  /*
  SocketHandler r;
  Sender s(&r);

  pthread_t rT, sT;

  pthread_create(&rT, NULL, SocketHandler::run, &r);
  pthread_create(&sT, NULL, Sender::run, &s);

  void *exitStatus;
  pthread_join(rT, &exitStatus);
  pthread_join(sT, &exitStatus);
  */
  return 0;
}

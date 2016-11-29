#include <iostream>
#include "Sender.hpp"
#include "Receiver.hpp"

int main()
{
  Receiver r;
  Sender s(&r);

  pthread_t rT, sT;

  pthread_create(&rT, NULL, Receiver::run, &r);
  pthread_create(&sT, NULL, Sender::run, &s);

  void *exitStatus;
  pthread_join(rT, &exitStatus);
  pthread_join(sT, &exitStatus);

  return 0;
}

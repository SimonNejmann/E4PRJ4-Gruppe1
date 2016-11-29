#include "util.hpp"
#include <stdlib.h>
#include <time.h>

namespace util {
  static bool started = false;

  void randSleep(int min, int max)
  {
    if (!started) {
      started = true;
      srand (time(NULL));
    }
    
    const int ms = 1000*1000; // 1 ms in ns
    unsigned long wait = (rand() % (max-min)) + min;

    struct timespec t;
    t.tv_sec = wait / 1000;  // whole seconds
    t.tv_nsec = (wait % 1000) * ms; // remaining nano-seconds
    nanosleep(&t, NULL);
  }

  int randVal(int min, int max)
  {
    if (!started) {
      started = true;
      srand (time(NULL));
    }
    
    return (rand() % (max-min)) + min;
  }
}

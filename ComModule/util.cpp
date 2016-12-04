#include "util.hpp"
#include <stdlib.h>
#include <time.h>

namespace util {
  static bool started = false;

  void randSleep(int min, int max)
  {
    const int ms = 1000*1000; // 1 ms in ns
    unsigned long wait = randVal(min, max);

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
    if (min == max)
      return min;
    
    return (rand() % (max-min)) + min;
  }

  int max(int a, int b)
  {
    return (a>b)?a:b;
  }

  int min(int a, int b)
  {
    return (a<b)?a:b;
  }
}

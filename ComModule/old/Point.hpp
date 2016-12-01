#ifndef POINT_HPP_
#define POINT_HPP_

#include "Message.hpp"

struct Point : public Message
{
  int x;
  int y;
  int z;
};

#endif // POINT_HPP_

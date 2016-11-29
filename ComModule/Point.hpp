#ifndef _POINT_HPP_
#define _POINT_HPP_

#include "Message.hpp"

struct Point : public Message
{
  int x;
  int y;
  int z;
};

#endif //_POINT_HPP_

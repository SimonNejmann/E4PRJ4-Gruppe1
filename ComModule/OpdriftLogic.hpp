#ifndef OPDRIFTLOGIC_HPP_
#define OPDRIFTLOGIC_HPP_

/*
  Class for handeling the data received from the
  opdrift, and the logic associated with it.
 */

class OpdriftLogic
{
public:
  OpdriftLogic()
    : inflated_(0)
  {}

  int constructBuffer(char *buf)
  {
    buf[0] = 'O'; // capital o
    buf[1] = inflated_;
    return 2;
  }

  bool newData(unsigned char status)
  {
    bool tmp = (inflated_ == status);
    inflated_ = status;
    return tmp;
  }

private:
  unsigned char inflated_;
};

#endif // OPDRIFTLOGIC_HPP_

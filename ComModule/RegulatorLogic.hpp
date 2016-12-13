#ifndef REGULATORLOGIC_HPP_
#define REGULATORLOGIC_HPP_

/*
  Class for handeling the data received from the
  regulator, and the logic associated with it.
 */

class RegulatorLogic
{
public:
  RegulatorLogic()
    : angle_(100), speed_(0), strafing_(false)
  {}

  int constructI2CBuffer(char *buf, bool inflated)
  {
    buf[0] = 0x00;
    buf[1] = angle_;
    buf[2] = speed_;
    if (strafing_) {
      buf[3] = static_cast<char>(0xFF);
    } else {
      buf[3] = 0x00;
    }
    if (inflated) {
      buf[4] = static_cast<char>(0xFF);
    } else {
      buf[4] = 0x00;
    }

    return 5;
  }

  int updateSpeed(unsigned char speed, char *buf, bool inflated)
  {
    speed_ = speed;
    return constructI2CBuffer(buf, inflated);
  }

  int updateAngleSteer(unsigned char angle, char *buf, bool inflated)
  {
    strafing_ = false;
    angle_ = angle;
    return constructI2CBuffer(buf, inflated);
  }

  int updateAngleStrafe(unsigned char angle, char *buf, bool inflated)
  {
    strafing_ = true;
    angle_ = angle;
    return constructI2CBuffer(buf, inflated);
  }

private:
  unsigned char angle_;
  unsigned char speed_;
  bool strafing_;
};

#endif // REGULATORLOGIC_HPP_

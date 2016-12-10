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

  int constructBuffer(char *buf)
  {
    buf[0] = 0x00;
    buf[1] = angle_;
    buf[2] = speed_;
    if (strafing_) {
      buf[3] = 0xFF;
    } else {
      buf[3] = 0x00;
    }

    return 4;
  }

  int updateSpeed(unsigned char speed, char *buf)
  {
    speed_ = speed;
    return constructBuffer(buf);
  }

  int updateAngleSteer(unsigned char angle, char *buf)
  {
    strafing_ = false;
    angle_ = angle;
    return constructBuffer(buf);
  }

  int updateAngleStrafe(unsigned char angle, char *buf)
  {
    strafing_ = true;
    angle_ = angle;
    return constructBuffer(buf);
  }

private:
  unsigned char angle_;
  unsigned char speed_;
  bool strafing_;
};

#endif // REGULATORLOGIC_HPP_

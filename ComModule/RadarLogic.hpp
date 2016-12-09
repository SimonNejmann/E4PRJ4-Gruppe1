#ifndef RADARLOGIC_HPP_
#define RADARLOGIC_HPP_

/*
  Class for handeling the data received from the
  radar, and the logic associated with it.

  For now, to get it working, this has been hardcoded
  to only handle the 4 directions the radar returns.
 */

class RadarLogic
{
public:
  RadarLogic()
    : dist_()
  {}

  bool newData(unsigned char dir, unsigned char dist)
  {
    int dirNum = dir / 50;
    // is the direction ok?
    if (dirNum > 3) 
      return false;
    // old reading?
    if (dist == dist_[dirNum])
      return false;

    // Update reading
    dist_[dirNum] = dist;
    return true;
  }

private:
  unsigned char dist_[4];
};

#endif // RADARLOGIC_HPP_

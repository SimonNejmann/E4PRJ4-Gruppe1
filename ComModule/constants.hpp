#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

namespace constants
{
  static const int UDP_SOCKET = 8575;
  static const int BUFFER_SIZE = 100;

  static const int I2C_DEVICE = 1;

  static const int I2C_RADAR_ADDR = 0x00;  // TODO
  static const int I2C_RADAR_LENGTH = 0;  // TODO

  static const int I2C_OPDRIFT_ADDR = 0x00;  // TODO
  static const int I2C_OPDRIFT_LENGTH = 0;  // TODO

  static const int I2C_CONTROLLER_ADDR = 0x00;  // TODO
  static const int I2C_CONTROLLER_LENGTH = 0;  // TODO

  static const int I2C_TEST_ADDR = 0x08;
  static const int I2C_TEST_LENGTH = 3;
}

#endif // CONSTANTS_HPP_

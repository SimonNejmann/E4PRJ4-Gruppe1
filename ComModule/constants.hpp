#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

namespace constants
{
  // Socket port
  static const int UDP_SOCKET = 8575;

  // Generel buffer size
  static const int BUFFER_SIZE = 100;

  // Timers
  static const int TIMER_INTERVAL_RADAR = 500; // ms
  static const int TIMER_INTERVAL_OPDRIFT = 200; // ms
  static const int TIMER_INTERVAL_KEEPALIVE = 1000; // ms

  // I2C
  static const int I2C_DEVICE = 1;
  // I2C: Radar
  static const int I2C_RADAR_ADDR = 0x00;  // TODO
  static const int I2C_RADAR_LENGTH = 1;  // TODO
  // I2C: Opdrift
  static const int I2C_OPDRIFT_ADDR = 0x00;  // TODO
  static const int I2C_OPDRIFT_LENGTH = 1;  // TODO
  // I2C: Regulator
  static const int I2C_REGULATOR_ADDR = 0x00;  // TODO
  static const int I2C_REGULATOR_LENGTH = 1;  // TODO
  // I2C: Test module
  static const int I2C_TEST_ADDR = 0x08;
  static const int I2C_TEST_LENGTH = 3;
}

#endif // CONSTANTS_HPP_

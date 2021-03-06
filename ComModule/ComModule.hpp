#ifndef COM_MODULE_HPP_
#define COM_MODULE_HPP_

#include "SocketHandler.hpp"
#include "I2CHandler.hpp"
#include "constants.hpp"
#include "RadarLogic.hpp"
#include "OpdriftLogic.hpp"
#include "RegulatorLogic.hpp"
#include "RecurringTimer.hpp"
#include "Thread.hpp"

class ComModule : public Thread
{
public:
  ComModule();
  ~ComModule();
  
  enum {
    TIMER_RADAR,
    TIMER_OPDRIFT,
    TIMER_KEEPALIVE,
    RECEIVE_I2C_PACKET_RADAR,
    RECEIVE_I2C_PACKET_OPDRIFT,
    RECEIVE_I2C_PACKET_TEST,
    RECEIVE_UDP_PACKET
  };

  struct PacketMessage : public Message {
    char buf_[constants::BUFFER_SIZE];
    int len_;
  };

private:
  MsgQueue mq_;
  SocketHandler sock_;
  I2CHandler i2c_;

  bool appAlive_;
  RadarLogic radar_;
  OpdriftLogic opdrift_;
  RegulatorLogic regulator_;

  RecurringTimer radarTimer_;
  RecurringTimer opdriftTimer_;
  RecurringTimer keepAliveTimer_;
  
  void runThread();

  // Message handlers
  void handleMsg(Message *msg, unsigned long id);

  void handleMsgTimerRadar(Message *msg);
  void handleMsgTimerOpdrift(Message *msg);
  void handleMsgTimerKeepalive(Message *msg);

  void handleMsgReceiveI2cPacketRadar(Message *msg);
  void handleMsgReceiveI2cPacketOpdrift(Message *msg);
  void handleMsgReceiveI2cPacketTest(Message *msg);

  void handleMsgReceiveUdpPacket(Message *msg);

};

#endif // COM_MODULE_HPP_

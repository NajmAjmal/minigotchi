// packet.h: header files for packet.cpp

#ifndef PACKET_H
#define PACKET_H

#include <Arduino.h>
#include "raw80211.h"
#include <ArduinoJson.h>

class PacketSender {
public:
  void sendJsonPayload();
  void sendJsonPayloadMultipleTimes(int count = 10, int delayBetweenSends = 100);
};

#endif // PACKET_H

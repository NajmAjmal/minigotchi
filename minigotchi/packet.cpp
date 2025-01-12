// packet.cpp: handles the sending of pwnagotchi packets

#include "packet.h"
#include "raw80211.h"
#include <ArduinoJson.h>

// set magic number(222 in hex)
const uint8_t MAGIC_NUMBER = 0xDE;

void PacketSender::sendJsonPayload() {
  
  // json object creation
  DynamicJsonDocument doc(1024);

  // all settings
  doc["epoch"] = 1;
  doc["face"] = "(◕‿‿◕)";
  doc["identity"] = "b9210077f7c14c0651aa338c55e820e93f90110ef679648001b1cecdbffc0090";
  doc["name"] = "minigotchi";

  JsonObject policy = doc.createNestedObject("policy");
  policy["advertise"] = true;
  policy["ap_ttl"] = 0;
  policy["associate"] = true;
  policy["bored_num_epochs"] = 0;

  JsonArray channels = policy.createNestedArray("channels");
  channels.add(1);
  channels.add(3);
  channels.add(4);
  channels.add(5);
  channels.add(6);

  policy["deauth"] = true;
  policy["excited_num_epochs"] = 1;
  policy["hop_recon_time"] = 1;
  policy["max_inactive_scale"] = 0;
  policy["max_interactions"] = 1;
  policy["max_misses_for_recon"] = 1;
  policy["min_recon_time"] = 1;
  policy["min_rssi"] = 1;
  policy["recon_inactive_multiplier"] = 1;
  policy["recon_time"] = 1;
  policy["sad_num_epochs"] = 1;
  policy["sta_ttl"] = 0;

  doc["pwnd_run"] = 0;
  doc["pwnd_tot"] = 0;
  doc["session_id"] = "84:f3:eb:58:95:bd";
  doc["uptime"] = 1;
  doc["version"] = "v1.0.0";

  String jsonString;
  if (serializeJson(doc, jsonString) == 0) {
    // handle errors here
    Serial.println("Failed to serialize JSON");
  } else {
    // put number in payload
    Raw80211::send(&MAGIC_NUMBER, sizeof(MAGIC_NUMBER));
    Raw80211::send(reinterpret_cast<const uint8_t*>(jsonString.c_str()), jsonString.length());

    Serial.println("Sent payload!");
  }
}

void PacketSender::sendJsonPayloadMultipleTimes(int count, int delayBetweenSends) {
    for (int i = 0; i < count; ++i) {
        sendJsonPayload();
        delay(delayBetweenSends);
    }
}
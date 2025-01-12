// pwnagotchi.h: header files for pwnagotchi.cpp

#ifndef PWNAGOTCHI_H
#define PWNAGOTCHI_H

#pragma once

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "raw80211.h"
#include <user_interface.h>

class Pwnagotchi {
public:
    Pwnagotchi();  // constructs/inits everything

    void detectAndHandlePwnagotchi();
    void detectPwnagotchi();
    void handlePwnagotchiDetection(const wifi_ieee80211_mac_hdr_t *hdr, int rssi, const unsigned char *buff, short unsigned int buff_len);
    String extractMAC(const unsigned char *buff);
    void getMAC(char* addr, const unsigned char* buff, int offset);

private:
    String essid;
    bool pwnagotchiDetected;

};

// global instance
extern Pwnagotchi pwnagotchi;

#endif // PWNAGOTCHI_H

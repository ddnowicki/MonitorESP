#pragma once

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

class udp {
  WiFiUDP ntpUDP;
  NTPClient timeClient;

 public:
  udp(const long utcOffsetInSeconds);
  std::pair<int, int> currentTime();
};

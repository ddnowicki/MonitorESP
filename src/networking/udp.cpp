#include "udp.hpp"

udp::udp(const long utcOffsetInSeconds)
    : timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds) {
  timeClient.begin();
}

std::pair<int, int> udp::currentTime() {
  timeClient.update();

  Serial.println(timeClient.getFormattedTime());
  return std::pair<int, int>(timeClient.getHours(), timeClient.getMinutes());
}
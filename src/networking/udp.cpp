#include "udp.hpp"

udp::udp(const long utcOffsetInSeconds)
    : timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds) {
  timeClient.begin();
}

std::pair<int, int> udp::currentTime() {
  timeClient.update();

  int hours = timeClient.getHours();
  int minutes = timeClient.getMinutes();

  return std::pair<int, int>(hours, minutes);
}
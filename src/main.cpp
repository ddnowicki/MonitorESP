#include <Arduino.h>

#include "config.hpp"
#include "displays/digits.hpp"
#include "displays/lcd.hpp"
#include "i2c/i2c.hpp"
#include "networking/udp.hpp"
#include "networking/wifi.hpp"

digits digits(12, 13);
i2c i2c;
lcd lcd(i2c.scan());
wifi wifi(NETNAME, PASSWORD);
udp udp(3600);

void setup() {
}

void loop() {
  digits.print(udp.currentTime());
  delay(1000);
}
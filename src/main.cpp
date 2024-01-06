#include <Arduino.h>

#include "config.hpp"
#include "json/json.hpp"
#include "displays/digits.hpp"
#include "displays/lcd.hpp"
#include "i2c/i2c.hpp"
#include "networking/udp.hpp"
#include "networking/wifi.hpp"

digits digits(12, 13);
i2c i2c;
lcd lcd5(i2c.scan());
udp udp(3600);
wifi net;
json json;

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n\n");

  net.init();

  std::pair<String, String> test = json.decompileSpec(net.requestGet(ADRESS));
  Serial.println(test.first);
  Serial.println(test.second);
}

void loop() {
  digits.print(udp.currentTime());
  std::pair<String, String> test = json.decompileSpec(net.requestGet(ADRESS));
  lcd5.print(test.first, 0);
  lcd5.print(test.second, 1);
  delay(500);
}
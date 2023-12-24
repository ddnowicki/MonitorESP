#include <Arduino.h>

#include "displays/lcd.hpp"
#include "i2c/i2c.hpp"

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n\n");

  i2c i2c;
  lcd lcd(i2c.scan());
}

void loop() { yield(); }
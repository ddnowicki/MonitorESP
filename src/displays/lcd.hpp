#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class lcd {
 public:
  lcd(int i2cAdress);
  void print(String data, uint8_t y);

 private:
  LiquidCrystal_I2C lcd2;
};

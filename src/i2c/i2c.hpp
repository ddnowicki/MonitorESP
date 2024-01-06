#pragma once

#include <Arduino.h>
#include <Wire.h>

class i2c {
  byte error, address;
  int nDevices;

 public:
  i2c();
  int scan();
};

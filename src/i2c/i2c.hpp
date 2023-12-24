#pragma once

#include <Arduino.h>
#include <Wire.h>

class i2c {

 public:
  i2c();
  int scan();
};

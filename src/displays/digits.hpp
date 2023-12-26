#pragma once

#include <Arduino.h>
#include <TM1637Display.h>

class digits {
  TM1637Display display;

 public:
  digits(uint8_t pinClk, uint8_t pinDIO);
  void print(std::pair<int, int>);
};

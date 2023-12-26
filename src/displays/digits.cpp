#include "digits.hpp"

digits::digits(uint8_t pinClk, uint8_t pinDIO) : display(pinClk, pinDIO) {
  display.setBrightness(0x0a);
}

void digits::print(std::pair<int, int> time) {
  display.showNumberDecEx(time.second, 0, true, 2, 2);
  display.showNumberDecEx(time.first, 0b01000000, true, 2, 0);
}
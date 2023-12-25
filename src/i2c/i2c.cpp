#include "i2c.hpp"

i2c::i2c() { 
  Wire.begin();
}

int i2c::scan() {
  nDevices = 0;

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      char addressStr[3];
      snprintf(addressStr, sizeof(addressStr), "%02X", address);

      return strtol(addressStr, NULL, 16);
    }
  }
  while(1);
  return 0x27;
}

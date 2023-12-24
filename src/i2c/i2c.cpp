#include "i2c.hpp"

i2c::i2c() { 
  Wire.begin();
}

int i2c::scan() {
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");

      nDevices++;
      char addressStr[3];
      snprintf(addressStr, sizeof(addressStr), "%02X", address);

      return strtol(addressStr, NULL, 16);
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found");
    Serial.println("killing process");
    while(1);
  }
  return 0x27;
}

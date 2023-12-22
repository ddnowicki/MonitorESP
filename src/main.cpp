#include <Arduino.h>
#include <IoAbstractionWire.h>
#include <LiquidCrystalIO.h>
#include <Wire.h>

LiquidCrystalI2C_RS_EN(lcd, 0x3F, false)

void i2cscanner() {
  byte error, address;
  int nDevices;
 
  Serial.println("Scanning...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
 
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");  
}

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n\n");

  Wire.begin();

  i2cscanner();
  
  lcd.begin(20, 4);
  lcd.configureBacklightPin(3);
  lcd.backlight();
  lcd.clear();
  Serial.println("lcd initialized");
}

void loop() {
}
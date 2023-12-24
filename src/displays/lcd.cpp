#include "lcd.hpp"

lcd::lcd(int i2cAdress) { 
  LiquidCrystal_I2C lcd2(i2cAdress,20,4);
  lcd2.init();
  lcd2.backlight();
  lcd2.setCursor(0,0);
  lcd2.print("Hello world!");
}
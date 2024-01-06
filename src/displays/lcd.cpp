#include "lcd.hpp"

lcd::lcd(int i2cAdress) : lcd2(i2cAdress, 20, 4) {
  lcd2.init();
  lcd2.backlight();
  lcd2.setCursor(0, 0);
  lcd2.print("Hello world!");
}

void lcd::print(String data, uint8_t y) {
  lcd2.setCursor(0, y);
  lcd2.print(data);
}

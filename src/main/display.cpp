#include "display.hpp"   
Display::Display() : lcd(0x27, 16, 2){
}

void Display::init(){
  this -> lcd.init();
  this -> lcd.backlight();
}

void Display::printDisplay(String firstRow, String secondRow){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(firstRow);
  lcd.setCursor(0,1);
  lcd.print(secondRow);
}

void Display::print(String str, short row) {
  // value can be 0 or 1
  //lcd.clear();
  lcd.setCursor(0,row);
  lcd.print(str);
  lcd.setCursor(0, row);
}

void Display::clear() {
  lcd.clear();
}

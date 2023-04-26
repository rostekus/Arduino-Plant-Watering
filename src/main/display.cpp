#include "display.hpp"   
Display::Display(float (*func)(int)) : lcd(0x27, 16, 2), getSensorReading(func) {
}

void Display::init(){
  this -> lcd.init();
  this -> lcd.backlight();
}

void Display::printScreen() {
  float value = this->getSensorReading(this->currentScreen);
  lcd.clear();
  lcd.print(this->screens[this->currentScreen][0]);
  lcd.setCursor(0,1);
  if (currentScreen != 3){
      lcd.print(value);
  }
  lcd.print(this->screens[this->currentScreen][1]);
}

void Display::setCurrentScreen(char choice){
  if (choice == 'd'){
    if(this->currentScreen<numOfScreens-1)
    this->currentScreen++;
    
        }
    if (choice == 'u' &&this->currentScreen >0 ){
    this->currentScreen--;
        }
    this->printScreen();
}
void Display::print(String str, short row) {
  // value can be 0 or 1
  //lcd.clear();
  lcd.setCursor(0,row);
  lcd.print(str);
  lcd.setCursor(0, row);
}

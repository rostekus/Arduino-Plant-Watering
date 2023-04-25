#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <LiquidCrystal_I2C.h>
const int numOfScreens = 4;

class Display{

  private:
    LiquidCrystal_I2C lcd;
    
    int currentScreen = 0;
    String screens[numOfScreens][2] = {{"Temperature","C"}, {"Temperature","F"}, 
    {"Moisture","%"}, {"SD CARD", "Write"} };
    float (*getSensorReading)(int);
  public: 
    Display(float (*func)(int));
    void printScreen();
    void init();
    void setCurrentScreen(char);
    void print(String, short);

};

#endif
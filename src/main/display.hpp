#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <LiquidCrystal_I2C.h>

class Display{

  private:
    LiquidCrystal_I2C lcd;
  public: 
    Display();
  
    void init();
    void printDisplay(String, String); 
    void print(String, short);

};

#endif
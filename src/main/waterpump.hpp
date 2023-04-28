#ifndef WATERPUMP_HPP
#define WATERPUMP_HPP
#include "Arduino.h"

const int RELAY_PIN = A2;
class WaterPump{
public:
    void turn_on_pump_for_n_seconds(int);
};

class WaterPumpController{
 // should take the waterpump as a parameter
 // and based on int temp and int moisture
 // should turn on the waterpump for a certain amount of time
  private:
    float minMoist;
    WaterPump* waterpump;
  public:
    void control_waterpump(float temp, float moisture);
    WaterPumpController(WaterPump* wp, float minMoist);
    WaterPumpController(){};
};




#endif
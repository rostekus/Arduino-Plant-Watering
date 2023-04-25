#ifndef WATERPUMP_HPP
#define WATERPUMP_HPP
#include "Arduino.h"

const int RELAY_PIN = A5;
class WaterPump{
public:
    void turn_on_pump_for_n_seconds(int);
};

class WaterPumpController{
 // should take the waterpump as a parameter
 // and based on int temp and int moisture
 // should turn on the waterpump for a certain amount of time
 private:
    int temp;
    int moisture;
    int light;
    WaterPump waterpump;
    public:
     void control_waterpump(float temp, float moisture, float light);
    WaterPumpController(WaterPump);

};




#endif
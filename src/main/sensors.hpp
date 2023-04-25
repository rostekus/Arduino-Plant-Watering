#ifndef SENSORS_HPP
#define SENSORS_HPP

#include <Arduino.h>
#include "sensor.hpp"

class MoistureSensor : Sensor{
private:
    /*const int airValue = 616;   //replace the value with value when placed in air using calibration code
    const int waterValue = 335; //replace the value with value when placed in water using calibration code
    int sSSoilMoistureValue = 0;
    int soilMoisturePercent = 0;*/
    int soilMoistureValue;
public:
    virtual double read(); 
};

class LightSensor : Sensor{
private:
    int value_A0;
    bool value_D7;
public:
    virtual double read();
};


#endif 

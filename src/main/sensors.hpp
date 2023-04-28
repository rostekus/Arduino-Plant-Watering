#ifndef SENSORS_HPP
#define SENSORS_HPP

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#include "sensor.hpp"

class MoistureSensor : Sensor{
private:
    /*const int airValue = 616;   //replace the value with value when placed in air using calibration code
    const int waterValue = 335; //replace the value with value when placed in water using calibration code*/
    const int airValue = 630;
    const int waterValue = 318;
    int sSSoilMoistureValue = 0;
    int soilMoisturePercent = 0;
    int soilMoistureValue;
public:
    virtual double read(); 
};

class TempSensor: Sensor{
//TODO
public:
    virtual double read();
};


#endif 

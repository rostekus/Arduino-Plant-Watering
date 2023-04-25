#include "sensors.hpp"
double MoistureSensor::read() {
        soilMoistureValue = analogRead(A0);
        //soilMoisturePercent = map(soilMoistureValue, airValue, waterValue, 0, 100);
        return soilMoistureValue;
}

double LightSensor::read(){
         value_A0 =analogRead(A0); 
        value_D7 = digitalRead(7);
        return value_A0;

}
double TempSensor::read(){
  return 0.0;
}
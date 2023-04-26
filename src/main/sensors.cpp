#include "sensors.hpp"
double MoistureSensor::read() {
        soilMoistureValue = analogRead(A3);
        //soilMoisturePercent = map(soilMoistureValue, airValue, waterValue, 0, 100);
        soilMoisturePercent = map(soilMoistureValue, this->airValue, this->waterValue, 0, 100);
        if(soilMoisturePercent <0){
          return 0.0;
        }
        return soilMoisturePercent;
}

double LightSensor::read(){
         value_A0 =analogRead(A0); 
        value_D7 = digitalRead(7);
        return value_A0;

}
double TempSensor::read(){
  return 0.0;
}
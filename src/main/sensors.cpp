#include "sensors.hpp"

OneWire oneWire(4);
DallasTemperature sensors(&oneWire);

double MoistureSensor::read() {
        soilMoistureValue = analogRead(A3);
        //soilMoisturePercent = map(soilMoistureValue, airValue, waterValue, 0, 100);
        soilMoisturePercent = map(soilMoistureValue, this->airValue, this->waterValue, 0, 100);
        if(soilMoisturePercent <0){
          return 0.0;
        }
        return soilMoisturePercent;
}

double TempSensor::read(){
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}
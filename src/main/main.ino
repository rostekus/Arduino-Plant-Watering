#include "sensors.hpp"
#include "display.hpp"
#include "joystick.hpp"
 

MoistureSensor moistSensor;
LightSensor lightSensor;
Display display(&readSensors);
Joystick joystick;

// maybe declaare trhis func somewhere else
float readSensors(int sensorId){
  if(sensorId ==0){
    return moistSensor.read();
  }
  if(sensorId ==1){
    return lightSensor.read();
  }
  return 0.0;
  }


void setup() {
  display.init();
}




void loop() {
  char choice = joystick.read_input();
  display.setCurrentScreen(choice);
}
    


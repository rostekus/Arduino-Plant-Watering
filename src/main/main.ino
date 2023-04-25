#include "sensors.hpp"
#include "display.hpp"
#include "joystick.hpp"
#include "waterpump.hpp" 

MoistureSensor moistSensor;
LightSensor lightSensor;
Display display(&readSensors);
Joystick joystick;
TempSensor tempSensor;
WaterPump waterPump;

// maybe declaare trhis func somewhere else
float readSensors(int sensorId){
  if(sensorId ==0){
    return tempSensor.read();
  }
  if(sensorId ==1){
    // calcalute F from C
    return tempSensor.read();
  }
  return 0.0;
  }


void setup() {
  // TODO
  //  SET up values for waterpump controller 
  display.init();
}




void loop() {
  char choice = joystick.read_input();
  display.setCurrentScreen(choice);
}
    


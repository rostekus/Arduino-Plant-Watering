#include "sensors.hpp"
#include "display.hpp"
#include "joystick.hpp"
#include "waterpump.hpp" 
#include "sdcard.hpp"

MoistureSensor moistSensor;
LightSensor lightSensor;
Display display(&readSensors);
Joystick joystick;
TempSensor tempSensor;
WaterPump waterPump;
SDCardWriter writer;

int setValueForWaterPump(int minValue, int maxValue,String settingPrompt, int defaultValue =0){
  int value= defaultValue;
  char input = ' ';
  while(input != 'r'){
  input = joystick.read_input();
  if (input == 'u') {
    value = min(value + 2, maxValue);
  }
  else if (input == 'd') {
    value = max(value - 2, minValue);
  }
  delay(100);
  String displayedSettingString = settingPrompt + String(value);
  Serial.println(displayedSettingString);
  display.print("Accept -> right", 1);
  display.print(displayedSettingString, 0);

  }
}


// maybe declaare trhis func somewhere else
float readSensors(int sensorId){
  if(sensorId ==0){
    return tempSensor.read();
  }
  if(sensorId ==1){
    // calcalute F from C
    return tempSensor.read();
  }
  if(sensorId ==2){
    String tempStr = "Temp [C] " + String(tempSensor.read());
    writer.writeString(tempStr);
    String moistStr = "Moist [%] " + String(moistSensor.read());
    writer.writeString(moistStr);
  }
  return 0.0;
  }


void setup() {
  // TODO
  //  SET up values for waterpump controller 
  display.init();
  Serial.begin(9600);
  int minMoisture = setValueForWaterPump(0, 100, "Set moist %: ");  
}




void loop() {
  char choice = joystick.read_input();
  display.setCurrentScreen(choice);
}
    


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
SDCardWriter writer;
WaterPumpController pumpController;
short setValueForWaterPump(int minValue, int maxValue,String settingPrompt, int defaultValue =0){
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
    return (tempSensor.read()* 9/5) + 32;
  }
  if(sensorId ==2){
    return moistSensor.read();
  }
  return 0.0;
  }

void loggingFunc(float temp, float moist){
    String tempStr = "Temp [C] " + String(temp);
    writer.writeString(tempStr);
    String moistStr = "Moist [%] " + String(moist);
    writer.writeString(moistStr);
}


void setup() {
  // TODO
  //  SET up values for waterpump controller 
  display.init();
  Serial.begin(9600);
  short minMoisture = setValueForWaterPump(0, 100, "Set moist %: ");  
  WaterPump* water_pump = new WaterPump();
  WaterPumpController pumpController(water_pump, minMoisture);
}





void loop() {
  char choice = joystick.read_input();
  display.setCurrentScreen(choice);
  pumpController.control_waterpump(tempSensor.read(), moistSensor.read());

}
    


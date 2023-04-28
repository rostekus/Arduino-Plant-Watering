#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "sensors.hpp"
#include "display.hpp"
#include "joystick.hpp"
#include "waterpump.hpp" 
#include "sdcard.hpp"
#include "menu.hpp"

extern const int numOfScreens;
extern String screens[numOfScreens][2];


class Controller {
  // Move to the cpp file
private:
  MoistureSensor moistSensor_;
  Display display_;
  Joystick joystick_;
  TempSensor tempSensor_;
  SDCardWriter writer_;
  WaterPumpController pumpController_;
  int currentScreen = 0;
  
public:
  Controller()
{
    // initialize objects
    display_ = Display();
    joystick_ = Joystick();
    display_.init();
    tempSensor_ = TempSensor();
    // moistSensor_ = MoistureSensor();
  
    writer_ = SDCardWriter();
  }

  void setupWaterPump(){
    float minMoisture = this->setValueForWaterPump(0, 100, "Set moist %: ");
    WaterPump* water_pump = new WaterPump();
    pumpController_ = WaterPumpController(water_pump, minMoisture);
  }

float setValueForWaterPump(int minValue, int maxValue,String settingPrompt, int defaultValue = 50){
  float value = defaultValue;
  char input = ' ';
  while(input != 'r'){
  input = joystick_.read_input();
  if (input == 'u') {
    value = min(value + 2, maxValue);
  }
  else if (input == 'd') {
    value = max(value - 2, minValue);
  }
  delay(100);
  String displayedSettingString = settingPrompt + String(value);
  display_.print("Accept -> right", 1);
  display_.print(displayedSettingString, 0);

  }

  return value;
}

void scrollScreen(){
  char choice = joystick_.read_input();
  if (choice == 'd'){
    if(this->currentScreen<numOfScreens-1)
    this->currentScreen++;
    
        }
    if (choice == 'u' &&this->currentScreen >0 ){
    this->currentScreen--;
        }
}

String getReading(){
  switch (this->currentScreen)
  {
  case 0:
    return String(tempSensor_.read());
    break;
  case 1:
    return String(tempSensor_.read()* 9/5 + 32);
    break;
  case 2:
    // return String(moistSensor_.read());
    break;
  case 3:
    return "SD CARD";
  }
  return "";
}


void menuLoop(){
  
  this->scrollScreen();
  String reading = this->getReading();
  String firstRow = screens[currentScreen][0];
  String secondRow = reading + screens[currentScreen][1];
  display_.printDisplay(firstRow, secondRow);
  // pumpController_->control_waterpump(tempSensor_.read(), moistSensor_.read());
  delay(500);
}

};

#endif //CONTROLLER_HPP

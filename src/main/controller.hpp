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
  WaterPumpController* pumpController_;
  int currentScreen = 0;
  long loggingPeriod = 60;
  long timePassedMilliseconds = 0;

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
    int minMoisture = this->setValueByUser(0, 100, "Set moist %: ");
    delay(200);
    this->loggingPeriod = this->setValueByUser(1, 1000, "Set log [m]: ", 5, 60);
    WaterPump* water_pump = new WaterPump();
    pumpController_ = new WaterPumpController(water_pump, minMoisture);
  }

int setValueByUser(int minValue, int maxValue, String settingPrompt, int step =2 , int defaultValue = 50){
  int value = defaultValue;
  char input = ' ';
  while(input != 'r'){
  input = joystick_.read_input();
  if (input == 'u') {
    value = min(value + step, maxValue);
  }
  else if (input == 'd') {
    value = max(value - step, minValue);
  }
  delay(100);
  if (value < 10){
    display_.clear();
  }
  String displayedSettingString = settingPrompt + String(value);
  display_.print("Accept -> right", 1);
  display_.print(displayedSettingString, 0);
  }
  return value;
}

int scrollScreen(){
  char choice = joystick_.read_input();
  if (choice == 'd'){
    if(this->currentScreen<numOfScreens-1)
    this->currentScreen++;
    
        }
    if (choice == 'u' &&this->currentScreen >0 ){
    this->currentScreen--;
        }
    return this-> currentScreen;
}

String getReading(int sceeenNum){
  switch (sceeenNum)
  {
  case 0:
    return String(tempSensor_.read());
    break;
  case 1:
    return String(tempSensor_.read()* 9/5 + 32);
    break;
  case 2:
    return String(moistSensor_.read());
    break;
}
  return "";
}

void loggingToSDCard(){
    // We dont want to log last screen
    for(int i = 0; i< numOfScreens-1; i++){
      String reading = this->getReading(i);
      String row = screens[i][0] + " " + reading + " " + screens[i][1];
      writer_.writeString(row);
    }
}

bool invokelogginFunc(){
 if(joystick_.read_input() == 'r') {
      return true;
    }
  return false;
}

void menuLoop(){
  
  bool isPumpActivated = pumpController_->control_waterpump(tempSensor_.read(), moistSensor_.read());
  if (isPumpActivated) {
    display_.clear();
  }
  int numScreen = this->scrollScreen();
  String reading = this->getReading(numScreen);
  String firstRow = screens[numScreen][0];
  String secondRow = reading + screens[numScreen][1];
  display_.printDisplay(firstRow, secondRow);
  if(numScreen == numOfScreens-1){
      if(invokelogginFunc() || timePassedMilliseconds > this->loggingPeriod*1000*60){
        //log if time passed or user pressed right
        //milliseconds in minute * seconds in minute * minutes
      display_.print("Saved  ",0);
      this->loggingToSDCard();
      delay(500);
      timePassedMilliseconds =0;
      display_.clear();
      
  }
  }

  delay(200);
  timePassedMilliseconds += 200;
}

};

#endif //CONTROLLER_HPP

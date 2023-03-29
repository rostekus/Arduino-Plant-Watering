#include <LiquidCrystal.h>

  #include "Menu.h"
  #include <string.h>
  #include <LiquidCrystal_I2C.h> //library for displaying on lcd
  //#include <DateTime.h> //library for displaying the clock
  LiquidCrystal_I2C lcd(0x27,16,2); 

Menu::Menu() {
    //are we really in need of this constructor?
  }

void Menu::mainMenu() {
  //TODO:
  //Apply date/hour in the first line
  lcd.print("Hi Plant Lover!\nPress R to play!");
  char wait = Serial.read();
  lcd.setCursor(0, 0);
  
  // char wait;  
  // wait = Serial.read();
  // if(wait != 'r') {
  //   lcd.print("Press r to choose current sensor");
  // }
  
  //lcd.print("Which sensor would you like to use.\n");//information which sensor has which id
  // else {    
  // chooseSensor(0, wait);
  // }

  //return wait;
  //TODO:
  //Wait for R and then:
  //chooseSensor(3, d);
}

void Menu::chooseSensor(int sensor_id, char action) {
  switch(action) {
    case 'u': //up - see previous sensor
      if(sensor_id == 0)//lcd.setCursor();
      lcd.print(sensors[3]);
      else
      lcd.print(sensors[sensor_id--]);
      break;
    case 'd': //down - see next sensor
      if(sensor_id == 3)
      lcd.print(sensors[0]);
      else
      lcd.print(sensors[sensor_id++]);
      break;
    case 'l': //left - return to main menu
      mainMenu();
      break;
    case 'r': //right - choose current sensor
      readSensorInfo(sensor_id);
      break;
    default:
      //TODO:
      //Catch err
      lcd.print("Incorrect value:\naction variable");
      break;
  }
}

void Menu::readSensorInfo(int sensor_id) {
  switch(sensor_id) {
    case 0:
      //temperature
      break;
    case 1:
      //light
      break;
    case 2:
      //soil moisture
      break;
    case 3:
      //buzzer
      break;
  }
}
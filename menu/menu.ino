#include "Menu.h"
  #include <LiquidCrystal_I2C.h> //library for displaying on lcd
  LiquidCrystal_I2C lcd(0x27,16,2); 

void setup() {
  // put your setup code here, to run once:
  //DateTime.sync(1230768000); // set jan 1 2009 as the default time
  Menu meniu;
  meniu.mainMenu();
}

void loop() {
  Menu choose;
  char wait;
  int sensor_id;
  lcd.print("Choose the sensor");
  sensor_id.Serial.read();
  lcd.print("Press r to confirm");
  wait = Serial.read();
  choose.chooseSenor(sensor_id, wait);
  // put your main code here, to run repeatedly:
}

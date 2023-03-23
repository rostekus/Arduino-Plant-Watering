  #include "Menu.h"
  #include <string.h>
  #include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C lcd(0x27,16,2); 

Menu::Menu(char action) {
    this->action=action;
  }

void Menu::menu(char c){
  String arr[4]={"Temp Sensor" , "Light Sensor" , "Soil moisture sensor" , "Buzzer"};

  int index = 0;
  int horizontalIndex = 0;
  switch (c){
    case 'l':
    if(horizontalIndex==0){
      lcd.print("Press r");
      //digitalClockDisplay();
    }
    else if(horizontalIndex==1){
      lcd.print(arr[0]);
    }
    else{
      lcd.print();
    }
    break;
    case 'r':
    break;
    case 'u':
    if(index==0) {
      index=3;
      }
      else{
    index--;
    }
    lcd.print(arr[index]);
    break;
    case 'd':
    if(index==3){
      index=0;
    }
    else{
    index++;
    }
    lcd.print(arr[index]);
    break;
    default:
    break;
  }
}
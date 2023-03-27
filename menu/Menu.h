#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>
//#include <DateTime.h>
#include <string.h>

class Menu {
private:
  String sensors[4] = {"Temperature" , "Light" , "Soil moisture" , "Buzzer"};

public:
  Menu();
  void mainMenu(); //menu start point, maybe displaying date and hour?
  void chooseSensor(int sensor_id, char action); //displaying avaiable sensors
  void readSensorInfo(int sensor_id); //reading info from sensor
};

//TODO:
//Error handling
//Time display
//Waiting for chars
//Display implementation

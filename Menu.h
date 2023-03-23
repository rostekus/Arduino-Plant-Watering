#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>
//#include <DateTime.h>

class Menu {
  char action;

public:
  Menu(char action);

  void menu(char c);
};
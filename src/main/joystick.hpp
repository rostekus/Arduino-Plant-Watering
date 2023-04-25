#ifndef JOYSTICK_HPP
#define JOYSTICK_HPP
#include "Arduino.h"
#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin
class Joystick{

private:
  char last_state = 'l';
public:
  char read_input();
};

#endif
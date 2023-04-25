#include "joystick.hpp"

char Joystick::read_input(){

    int x_value = analogRead(VRX_PIN);
    int y_value = analogRead(VRY_PIN);

    if (y_value < 100){
      //this->last_state = 'u';
        return 'u';
    }
    else if (y_value > 900){
      //this->last_state = 'd';
        return 'd';
    }
    else if (x_value > 900){
      //this->last_state = 'r';
        return 'r';
    }
    else if (x_value < 100){
      //this->last_state = 'l';
        return 'l';
    }

    return ' ';
}
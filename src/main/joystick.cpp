#include "joystick.hpp"

char Joystick::read_input(){

    int x_value = analogRead(VRX_PIN);
    int y_value = analogRead(VRY_PIN);

    if (y_value == 0){
      this->last_state = 'd';
        return 'd';
    }
    else if (y_value == 1023){
      this->last_state = 'u';
        return 'u';
    }
    else if (x_value == 1023){
      this->last_state = 'l';
        return 'l';
    }
    else if (x_value == 0 && last_state == 'u'){
      this->last_state = 'r';
        return 'r';
    }

    return this->last_state;
}
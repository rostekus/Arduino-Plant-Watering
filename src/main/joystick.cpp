#include "joystick.hpp"

char Joystick::read_input(){

    int x_value = analogRead(VRX_PIN);
    int y_value = analogRead(VRY_PIN);

    if (y_value < 100){
        return 'u';
    }
    else if (y_value > 900){
        return 'd';
    }
    else if (x_value > 900){
        return 'r';
    }
    else if (x_value < 100){
        return 'l';
    }

    return this->last_state;
}
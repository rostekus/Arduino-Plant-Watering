#include "joystick.hpp"

char Joystick::read_input(){

    int x_value = analogRead(VRX_PIN);
    int y_value = analogRead(VRY_PIN);

    if (y_value == 0){
        return 'd';
    }
    else if (y_value == 1023){
        return 'u';
    }
    else if (x_value == 1023){ 
        return 'l';
    }
    else if (x_value == 0 ){
        return 'r';
    }

    return this->last_state;
}
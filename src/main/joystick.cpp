#include "joystick.hpp"

char Joystick::read_input(){

    int x_value = analogRead(VRX_PIN);
    int y_value = analogRead(VRY_PIN);

<<<<<<< HEAD
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
=======
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
>>>>>>> 6bb9d7ecf702a5992f103791f57da45574b3492d
        return 'r';
    }
    else if (x_value < 100){
      //this->last_state = 'l';
        return 'l';
    }

    return ' ';
}
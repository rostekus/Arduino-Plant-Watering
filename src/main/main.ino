#include "controller.hpp"

Controller* controller;

void setup() {
  controller = new Controller();
  controller->setupWaterPump();
}

void loop() {

controller->menuLoop();
}
    


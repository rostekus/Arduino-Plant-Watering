#include "waterpump.hpp"

void WaterPump::turn_on_pump_for_n_seconds(int seconds){

    pinMode(RELAY_PIN, OUTPUT);
    delay(1000 * seconds);
    pinMode(RELAY_PIN, INPUT);
}

bool WaterPumpController::control_waterpump(float temp, float moisture){
    if (moisture < this->minMoist) {
      waterpump->turn_on_pump_for_n_seconds(3);
      return true;
    }
  return false;
}

WaterPumpController::WaterPumpController(WaterPump* wp, float minMoist) {
    this->waterpump = wp;
    this->minMoist = minMoist;
}
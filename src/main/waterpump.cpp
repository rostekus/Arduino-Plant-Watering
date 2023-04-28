#include "waterpump.hpp"

void WaterPump::turn_on_pump_for_n_seconds(int seconds){
    digitalWrite(RELAY_PIN, HIGH);
    delay(1000 * seconds);
    digitalWrite(RELAY_PIN, LOW);
}

void WaterPumpController::control_waterpump(float temp, float moisture){
  pinMode(RELAY_PIN, INPUT);
    if (moisture < this->minMoist) {
      pinMode(RELAY_PIN, OUTPUT);
        waterpump->turn_on_pump_for_n_seconds(3);
    }
}

WaterPumpController::WaterPumpController(WaterPump* wp, float minMoist) {
    this->waterpump = wp;
    this->minMoist = minMoist;
}
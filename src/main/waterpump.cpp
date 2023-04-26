#include "waterpump.hpp"

void WaterPump::turn_on_pump_for_n_seconds(int seconds){
    digitalWrite(RELAY_PIN, HIGH);
    delay(1000 * seconds);
    digitalWrite(RELAY_PIN, LOW);
}

void WaterPumpController::control_waterpump(float temp, float moisture){
    if (moisture < minMoist) {
        waterpump->turn_on_pump_for_n_seconds(60); // turning on pump for 1 min
    }
}

WaterPumpController::WaterPumpController(WaterPump* wp, short minMoist) {
    this->waterpump = wp;
    this -> minMoist = minMoist;
}
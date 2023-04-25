#include "waterpump.hpp"

void WaterPump::turn_on_pump_for_n_seconds(int seconds){
    digitalWrite(RELAY_PIN, HIGH);
    delay(1000 * seconds);
    digitalWrite(RELAY_PIN, LOW);
}

void WaterPumpController::control_waterpump(float temp, float moisture, float light){}

WaterPumpController::WaterPumpController(WaterPump wp) {
    waterpump = wp;
}
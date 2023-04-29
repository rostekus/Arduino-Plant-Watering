# Arduino Plant Watering System

This repository contains code for an Arduino-based plant watering system that uses a soil moisture sensor and a water pump to water plants as needed. The system also includes a temperature sensor and an SD card for logging data.

## Devices used
- Arduino Uno (atmega328p)
- Joystick
- Soil Moisture Sensor v1.2
- Temperature sensor ds18b20
- SD Card
- Relay 5V
- Water pump 5V

## How it works
The system measures the soil moisture level using the moisture sensor and uses this information to determine if the plant needs watering. If the moisture level is below a certain threshold, the Arduino activates the water pump using the relay to water the plant. The system also displays the temperature and moisture level on an LCD screen and allows the user to log this data to the SD card.


#include <Arduino.h>

#include "epd_driver.h"
#include "utilities.h"

#include <header.h>

int battery = -1;

void setup() {
    //begin things
    Serial.begin(115200);
    Serial.println("Start DoorSign Client ...");

    Serial.println("EPD init ...");
    epd_init();
    epd_poweron();
    epd_clear();
    epd_poweroff();

    readEEPROM();
}

void loop() {
    //eeprominfo();
    delay(3000);
    readEEPROM();
    delay(3000);
}

#include <Arduino.h>

#include "epd_driver.h"
#include "utilities.h"
#include "firasans.h"

#include <header.h>

int battery = -1;
bool readroom = false;
uint8_t *framebuffer;

void setup() {
    //begin things
    Serial.begin(115200);
    Serial.println("Start DoorSign Client ...");

    Serial.println("Framebuffer init ...");
    framebuffer = (uint8_t *)ps_calloc(sizeof(uint8_t), EPD_WIDTH * EPD_HEIGHT / 2);
    if (!framebuffer){
        Serial.println("Framebuffer init didn`t work!");
    }
    memset(framebuffer, 0xFF, EPD_WIDTH * EPD_HEIGHT / 2);

    Serial.println("EPD init ...");
    epd_init();

    epd_poweron();
    epd_clear();

    epd_poweroff();

    readEEPROM();
    connectwifi();
    rtctimeset();
    
    readroom = readRoom();
    if (readroom == false)
    {
        Serial.println("Printing Error Picture ...");
        errormenu(1);
        //esp_deep_sleep(300000); //5min
    }
}

void loop() {
    //eeprominfo();
    delay(3000);
    //readEEPROM();
    delay(3000);
}


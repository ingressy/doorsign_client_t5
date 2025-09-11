#include <EEPROM.h>

#define EEPROM_SIZE 512

const int ssidadd = 0;
const char* ssiddata = "";
const int passadd = 20;
const char* passdata = "";

void setup() {
    Serial.begin(115200);
    Serial.println("DoorSign Client | Programmer");

    Serial.println("Writing WiFi Data ...");
    EEPROM.writeString(ssidadd, ssiddata);
    EEPROM.writeString(passadd, passdata);
    EEPROM.commit();

  Serial.println("Finished Writing Data");
}

void loop() {

}

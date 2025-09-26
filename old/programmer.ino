#include <EEPROM.h>

#define EEPROM_SIZE 512

const int ssidadd = 0;
const String ssiddata = "";
const int passadd = 20;
const String passdata = "";

const int crcadd = 500;
const int roomadd = 50;
const float room = 2.311;

void setup() {
  EEPROM.begin(EEPROM_SIZE);
  Serial.begin(115200);

  Serial.println("DoorSign Client | Programmer");

  Serial.println("Writing WiFi Data ...");
  EEPROM.writeString(ssidadd, ssiddata);
  EEPROM.writeString(passadd, passdata);
  EEPROM.commit();

  Serial.println("Writing CRC Data ...");

  uint16_t sum = 0;
  for (size_t i = 0; i < (ssiddata.length() + passdata.length()); i++) {
    if (i < ssiddata.length()) sum += (uint8_t)ssiddata[i];
    else sum += (uint8_t)passdata[i - ssiddata.length()];
  }
  uint8_t calc = sum & 0xFF;
  EEPROM.writeUChar(crcadd, calc);
  EEPROM.commit();

  Serial.println("Writing Room Number ...");
  EEPROM.writeFloat(roomadd, room);
  EEPROM.commit();

  Serial.println("Finished Writing Data!");

  Serial.println("Read Data Back ...");
  Serial.println("SSID: " + EEPROM.readString(ssidadd));
  Serial.println("Password: " + EEPROM.readString(passadd));

  Serial.println("CRC: " + String(EEPROM.readUChar(crcadd)));
  Serial.println("Room: " + String(EEPROM.readFloat(roomadd),3));

  Serial.println("Finish Programming DoorSign!")
}

void loop() {

}

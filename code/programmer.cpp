#include <EEPROM.h>
#include <Arduino.h>

#define EEPROM_SIZE 512

const int ssidadd = 0;
const String ssiddata = "";
const int passadd = 20;
const String passdata = "";

const int crcadd = 500;
const int idadd = 50;
const int id = 0;

void eeprominfo() {
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

  Serial.println("Writing ID Number ...");
  EEPROM.writeInt(idadd, id);
  EEPROM.commit();

  Serial.println("Finished Writing Data!");

  Serial.println("Read Data Back ...");
  Serial.println("SSID: " + EEPROM.readString(ssidadd));
  Serial.println("Password: " + EEPROM.readString(passadd));

  Serial.println("CRC: " + String(EEPROM.readUChar(crcadd)));
  Serial.println("ID: " + String(EEPROM.readInt(idadd)));

  Serial.println("Finish Programming DoorSign!");
}

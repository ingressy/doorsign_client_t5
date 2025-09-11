#include <WiFi.h>
#include <EEPROM.h>

//512 Byte | one letter a Byte
#define EEPROM_SIZE 512

//EEPROM info | NAMEadd = address | NAMEdata = data || address equals letter  || COUNT LETTERS!!!
const int ssidadd = 0;
const int passadd = 20;

//ssid and password for wifi
String ssid = "";
String password = "";

void setup() {
  //begin things
  Serial.begin(115200);
  Serial.println("Start DoorSign Client ...");
  readEEPROM();
  connectwifi();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void connectwifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("Connecting to WiFi Network ...");

  //wait antill wifi is connected 
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.println("\nConnected to the " + String(ssid) + " network");
  Serial.println("IP:" + WiFi.localIP().toString());

}

void readEEPROM() {
  Serial.println("Begin to read EEPROM ...");

  EEPROM.begin(EEPROM_SIZE);

  //check if EEPROM Address is initialized || didnt check corruption
  if (EEPROM.read(ssidadd) != 0xFF) {
    ssid = EEPROM.readString(ssidadd);
    Serial.println("Found SSID Data in EEPROM ...");
  } else {
    Serial.println("Didnt find SSID Data in EEPROM!");
    loop();
  }
  if (EEPROM.read(passadd) != 0xFF) {
    password = EEPROM.readString(passadd);
    Serial.println("Found Password Data in EEPROM ...");
  } else {
    Serial.println("Didnt find Password Data in EEPROM!");
    loop();
  }
  
  Serial.println("End to read EEPROM ...");
}

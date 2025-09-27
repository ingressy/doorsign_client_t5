#pragma once //ruft die datei nur einmal auf
extern String ssid, password, IP, MAC;
extern uint8_t *framebuffer;
extern int id;

extern struct tm timeinfo;
extern char time_str[32];


//Declaration
void readEEPROM();
bool readRoom();

void eeprominfo();

void errormenu(int menu);

void connectwifi();
void rtctimeset();

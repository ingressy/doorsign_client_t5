#include <Arduino.h>
#include <WiFi.h>

#include <time.h>

#include <header.h>

String IP = "-1.-1.-1.-1";
String MAC = "";

static const char* ntpserver = "pool.ntp.org";
static long gmtoffset_sec = 3600;
static int daylightoffset_sec = 3600;

char time_str[32];

void connectwifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("Connecting to WiFi Network ...");

  //wait until wifi is connected 
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.println("\nConnected to the " + String(ssid) + " network");
  IP = WiFi.localIP().toString();
  MAC = WiFi.macAddress();

  Serial.println("IP:" + IP);
  Serial.println("Mac:"+ MAC);
}

void rtctimeset() {
    configTime(gmtoffset_sec, daylightoffset_sec, ntpserver);
    struct tm timeinfo;
    getLocalTime(&timeinfo);

    Serial.println(&timeinfo, "Aktuelle Zeit: %Y-%m-%d %H:%M:%S");

    strftime(time_str, sizeof(time_str), "%d.%m.%Y um %H:%M:%S", &timeinfo); 
}

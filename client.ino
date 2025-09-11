#include <WiFi.h>

//ssid and password for wifi
const char* ssid = "";
const char* password = "";

void setup() {
  Serial.begin(115200);
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

  Serial.println("Connected to the " + String(ssid) + " network");
  Serial.println("IP:" + WiFi.localIP().toString());


}

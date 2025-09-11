# doorsign_client_t5
Doorsign Client for LilyGo T5-S3 EPaper

# Imported Settings for Arduino IDE
| Arduino IDE Setting  | Value |
|----------------------|-------|
|Board |	ESP32S3 Dev Module|
|Port |	Your port|
|USB CDC On Boot |	Enable|
|CPU Frequency |	240MHZ(WiFi)|
|Core Debug Level |	None|
|USB DFU On Boot |	Disable|
|Erase All Flash Before Sketch Upload |	Disable|
|Events Run On |	Core1|
|Flash Mode |	QIO 80MHZ|
|Flash Size |	16MB(128Mb)|
|Arduino Runs On |	Core1|
|USB Firmware MSC On Boot |	Disable|
|Partition Scheme |	16M Flash(3M APP/9.9MB FATFS)|
|PSRAM |	OPI PSRAM|
|Upload Mode |	UART0/Hardware CDC|
|Upload Speed |	921600|
|USB Mode |	CDC and JTAG|

its from https://github.com/Xinyuan-LilyGO/LilyGo-EPD47/tree/esp32s3

# EEPROM Things
| Address | Data |
|---------|------|
|000-019|SSID |
|020-512| Password|

#include <Arduino.h>
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

static const int RXPin = 1, TXPin = 3;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps; // The TinyGPS++ object
SoftwareSerial ss(RXPin, TXPin); // The serial connection to the GPS device

void setup() {
Serial.begin(115200);
Serial.println("*****************************************************");

  ss.begin(GPSBaud);
}
void displayInfo() {
  if (gps.location.isValid()) {
double latitude = (gps.location.lat());
double longitude = (gps.location.lng());
Serial.println(latitude);
Serial.println(longitude);
}
}
void loop() {
  while (ss.available() > 0){
  if (gps.encode(ss.read())){
  displayInfo();
  }}
}


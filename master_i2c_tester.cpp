#include <Wire.h>
#include <Arduino.h>

#define SLAVEID1 0x1
#define SLAVEID2 0x2

#define FWD 1
#define REV 0

void sendCommand(const int slaveid, const int dir) {
  Wire.beginTransmission(slaveid); // transmit to device #8
  Wire.write(dir);              // sends one byte
  Wire.endTransmission();    // stop transmitting
}

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("Begin Init.");
  Wire.begin();
  Serial.println("Finsihed Init.");
  Serial.end();
}

void loop() {
  sendCommand(SLAVEID1, FWD);
  sendCommand(SLAVEID2, FWD);
  delay(2000);
  sendCommand(SLAVEID1, REV);
  sendCommand(SLAVEID2, FWD);
  delay(2000);
  sendCommand(SLAVEID1, FWD);
  sendCommand(SLAVEID2, REV);
  delay(2000);
  sendCommand(SLAVEID1, REV);
  sendCommand(SLAVEID2, REV);
  delay(2000);
}

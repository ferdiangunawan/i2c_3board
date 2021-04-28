// Chapter 7 - Communications
// I2C Master
// By Cornel Amariei for Packt Publishing

// Include the required Wire library for I2C
#include <Wire.h>

String y = "ini Y";

void setup() {
  // Start the I2C Bus as Master
  Wire.begin(); 
}

void loop() {
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(y.c_str());              // sends y 
  Wire.endTransmission();    // stop transmitting

  delay(1000);
}

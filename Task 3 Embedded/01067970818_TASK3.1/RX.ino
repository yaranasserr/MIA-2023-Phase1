#include <Wire.h>

const int buttonPin1 = 12;
const int buttonPin2 = 13;

void setup() {
  Wire.begin();
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
}

void loop() {
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);

  Wire.beginTransmission(9);  // Address of the receiver Arduino
  Wire.write(buttonState1);
  Wire.write(buttonState2);
  Wire.endTransmission();

  delay(200);  
}

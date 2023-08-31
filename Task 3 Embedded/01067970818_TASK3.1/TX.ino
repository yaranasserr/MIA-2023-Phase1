#include <Wire.h>

const int LED = 9;

void setup() {
  Wire.begin(9);  // Address of this Arduino as a receiver
  Wire.onReceive(receiveEvent);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {

}

void receiveEvent(int bytes) {
  if (Wire.available() >= 2) {
    int buttonState1 = Wire.read();
    int buttonState2 = Wire.read();

    int intensity = 0;
    String message = "No message";

    if (buttonState1 == 1 && buttonState2 == 0) {
      intensity = 128;  // 50% of maximum
      message = "Vector focused";
    } else if (buttonState1 == 0 && buttonState2 == 1) {
      intensity = 191;  // 75% of maximum
      message = "Vector distracted";
    } else if (buttonState1 == 1 && buttonState2 == 1) {
      intensity = 255;  // 100% of maximum
      message = "Glitch";
    }

    analogWrite(LED, intensity);
    Serial.print("B1=");
    Serial.print(buttonState1);
    Serial.print(", B2=");
    Serial.print(buttonState2);
    Serial.print(" ");
    Serial.println(message);
  }
}

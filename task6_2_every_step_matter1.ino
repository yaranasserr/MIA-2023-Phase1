// C++ code
//
#define PinA 6
#define PinB 7
long long counter =0;
void setup()
{
// Encoders setup
    pinMode(PinA, INPUT_PULLUP); 
    pinMode(PinB, INPUT_PULLUP);

    attachInterrupt(PinA, ISR_encoderPinA, CHANGE);
    attachInterrupt(PinB, ISR_encoderPinB, CHANGE);

}
void loop() {
  //Nothing
}

void ISR_encoderPinA(void)
{
   if (digitalRead(PinB) != digitalRead(PinA)) 
    counter++; 
   else 
    counter--;
}

void ISR_encoderPinB(void)
{
  if (digitalRead(PinA)== digitalRead(PinB)) 
       counter--;
  else 
    counter++;
  }
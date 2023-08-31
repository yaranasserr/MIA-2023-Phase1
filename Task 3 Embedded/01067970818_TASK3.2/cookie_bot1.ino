// Define ultrasonic sensor pins
const int triggerPin1 = 3; // Trigger Pin for first Ultrasonic Sensor
const int echoPin1 = 2;    // Echo Pin for first Ultrasonic Sensor

const int triggerPin2 = 5; // Trigger Pin for second Ultrasonic Sensor
const int echoPin2 = 4;    // Echo Pin for second Ultrasonic Sensor

const int triggerPin3 = 7; // Trigger Pin for third Ultrasonic Sensor
const int echoPin3 = 6;    // Echo Pin for third Ultrasonic Sensor

const int triggerPin4 = 9; // Trigger Pin for fourth Ultrasonic Sensor
const int echoPin4 = 8;    // Echo Pin for fourth Ultrasonic Sensor

// Define room dimensions
const float CHAMBER_WIDTH = 5.0;  // in meters
const float CHAMBER_HEIGHT = 6.0; // in meters

void setup() {
  Serial.begin(9600);

  // Set trigger pins as OUTPUT
  pinMode(triggerPin1, OUTPUT);
  pinMode(triggerPin2, OUTPUT);
  pinMode(triggerPin3, OUTPUT);
  pinMode(triggerPin4, OUTPUT);

  // Set echo pins as INPUT
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);
}

void loop() {
  float x, y;

  x = calculateXPosition();
  y = calculateYPosition();

  x = constrain(x, 0.0, CHAMBER_WIDTH);
  y = constrain(y, 0.0, CHAMBER_HEIGHT);

  Serial.print("Bot Position (x, y): ");
  Serial.print(x);
  Serial.print(" meters, ");
  Serial.print(y);
  Serial.println(" meters");

  delay(1000);
}

float calculateXPosition() {
  float xRight = calculatePosition(triggerPin2, echoPin2);
  float xLeft = calculatePosition(triggerPin4, echoPin4);
  return (xRight + xLeft) / 2.0;
}

float calculateYPosition() {
  float yFront = calculatePosition(triggerPin1, echoPin1);
  float yBack = calculatePosition(triggerPin3, echoPin3);
  return (yFront + yBack) / 2.0;
}

float calculatePosition(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW); //intial state
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH); //iniate the ultrasonic pulse transmission
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);//Set the trigger pin back to LOW to end the trigger pulse

  long duration = pulseIn(echoPin, HIGH); // pulseIn() function to measure the duration of the echo pulse
  float distance = duration * 0.000343 / 2.0; // Speed of sound is approximately 343 m/s

  // Calculate position within the room
  return (CHAMBER_WIDTH - distance) / 2.0;
}

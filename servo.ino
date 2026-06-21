#include <Servo.h>

int ldrPin = A0;
int servoPin = 6;
int threshold; 
Servo myservo;

void setup() {
  myservo.attach(servoPin);
  myservo.write(50);
  Serial.begin(9600);

  Serial.println("Calibrating... Keep screen clear.");
  delay(2000); // Wait for you to place it on the white screen
  
  int ambientLight = analogRead(ldrPin);
  // Set threshold to 20% lower than the white screen brightness
  threshold = ambientLight - (ambientLight * 0.20); 
  
  Serial.print("White Screen Value: ");
  Serial.println(ambientLight);
  Serial.print("Threshold set to: ");
  Serial.println(threshold);
}

void loop() {
  int ldrValue = analogRead(ldrPin);

  if (ldrValue < threshold) {
    myservo.write(110); // Adjust this angle so it doesn't hit too hard
    delay(50);
    myservo.write(50);
    delay(100); // Shortened delay to be ready for the next cactus
  }
}
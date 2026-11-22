#include <Servo.h>

Servo keyServo;

unsigned long previousMillis = 0;
const unsigned long interval = 60000; // 1 minute = 60000 milliseconds
//const unsigned long interval = 240000; // 4 minutes = 240000 milliseconds
void setup() {
  keyServo.attach(9);  // Servo signal connected to D9
  keyServo.write(0);   // Start position (no press)

  // First press immediately at startup
  delay(1000);          
  keyServo.write(20);   // Press
  delay(500);           
  keyServo.write(0);    // Release
  
  previousMillis = millis();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Press key
    keyServo.write(20);   
    delay(500);           
    keyServo.write(0);    
  }
}
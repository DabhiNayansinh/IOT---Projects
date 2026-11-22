/*
Code Name: Arduino Bluetooth Car with Front and Back Light Control
Code URI: https://circuitbest.com/category/arduino-projects/
Before uploading the code you have to install the "Adafruit Motor Shield" library
Open Arduino IDE >> Go to sketch >> Include Libray >> Manage Librays...  >> Search "Adafruit Motor Shield" >> Install the Library
AFMotor Library: https://learn.adafruit.com/adafruit-motor-shield/library-install
Author: Make DIY
Author URI: https://circuitbest.com/author/admin/
Description: This program is used to control a robot using an app that communicates with Arduino through an HC-05 Bluetooth Module.
App URI: https://bit.ly/3mn6LuZ
Version: 1.0
License: Remixing or Changing this Thing is allowed. Commercial use is not allowed.
*/
 
#include <AFMotor.h>
 
//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
 
int val;
int Speeed = 255;
int delay1 = 300;
// int LED1 = 9;
// int LED2 = 10;
 
 
void setup(){
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
  // pinMode(LED1, OUTPUT);
  // pinMode(LED2, OUTPUT);
}
void loop(){
  if(Serial.available() > 0){
    val = Serial.read();
 
    Stop(); //initialize with motors stoped
 
          if (val == 'F'){
          forward();
          }
          if (val == 'B'){
          back();
          }
          if (val == 'L'){
          left();
          }
          if (val == 'R'){
          right();
          }
          if (val == 'I'){
          topright();
          }
          if (val == 'J'){
          topleft();
          }
          if (val == 'K'){
          bottomright();
          }
          if (val == 'M'){
          bottomleft();
          }
          if (val == 'A'){
          pattern1();
          pattern1();
          }
          if (val == 'D'){
          pattern2();
          pattern2();
          }
          if (val == 'C'){
          pattern3();
          pattern3();
          }
          if (val == 'X'){
          pattern4();
          }
          if (val == 'Y'){
          pattern5();
          }
          if (val == 'Z'){
          pattern6();
          }
          if (val == 'T'){
          Stop();
          }
  }
}
 
void forward(){
  motor1.setSpeed(Speeed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speeed);
  motor2.run(BACKWARD);
 
  motor3.setSpeed(Speeed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speeed);
  motor4.run(FORWARD);
 
 
  // digitalWrite(LED1, HIGH);
  // digitalWrite(LED2, LOW);
}
void back(){
  motor1.setSpeed(Speeed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speeed);
  motor2.run(FORWARD);
 
  motor3.setSpeed(Speeed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speeed);
  motor4.run(BACKWARD);
 
 
    // digitalWrite(LED2, HIGH);
    // digitalWrite(LED1, LOW);
}
void left(){
  motor1.setSpeed(Speeed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speeed);
  motor2.run(FORWARD);
 
  motor3.setSpeed(Speeed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speeed);
  motor4.run(FORWARD);
 
  // digitalWrite(LED1, HIGH);
  // digitalWrite(LED2, HIGH);
}
void right(){
  motor1.setSpeed(Speeed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speeed);
  motor2.run(BACKWARD);
 
  motor3.setSpeed(Speeed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speeed);
  motor4.run(BACKWARD);
 
  // digitalWrite(LED1, HIGH);
  // digitalWrite(LED2, HIGH);
}
void topleft(){
  motor1.setSpeed(Speeed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speeed);
  motor2.run(BACKWARD);
 
  motor3.setSpeed(Speeed/2.4);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speeed/2.4);
  motor4.run(FORWARD);
 
    // digitalWrite(LED1, HIGH);
    // digitalWrite(LED2, LOW);
}
 
void topright(){
  motor1.setSpeed(Speeed/2.4);
  motor1.run(FORWARD);
  motor2.setSpeed(Speeed/2.4);
  motor2.run(BACKWARD);
 
  motor3.setSpeed(Speeed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speeed);
  motor4.run(FORWARD);
 
    // digitalWrite(LED1, HIGH);
    // digitalWrite(LED2, LOW);
}
void bottomleft(){
  motor1.setSpeed(Speeed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speeed);
  motor2.run(FORWARD);
 
  motor3.setSpeed(Speeed/2.4);
  motor3.run(FORWARD);
  motor4.setSpeed(Speeed/2.4);
  motor4.run(BACKWARD);
 
    // digitalWrite(LED2, HIGH);
    // digitalWrite(LED1, LOW);
 
}
void bottomright(){
  motor1.setSpeed(Speeed/2.4);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speeed/2.4);
  motor2.run(FORWARD);
 
  motor3.setSpeed(Speeed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speeed);
  motor4.run(BACKWARD);
 
    // digitalWrite(LED2, HIGH);
    // digitalWrite(LED1, LOW);
}
void Stop(){
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE);
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
 
    // digitalWrite(LED1, LOW);
    // digitalWrite(LED2, LOW);
}
 
 
void pattern1(){
    // digitalWrite(LED1, HIGH);
    delay(delay1);
    // digitalWrite(LED1, LOW);
    delay(delay1);
 
    // digitalWrite(LED2, HIGH);
    delay(delay1);
    // digitalWrite(LED2, LOW);
    delay(delay1);
}
void pattern2(){
 
    // digitalWrite(LED1, HIGH); delay(75);
    // digitalWrite(LED1, LOW); delay(75);
    // digitalWrite(LED2, HIGH); delay(75);
    // digitalWrite(LED2, LOW); delay(75);
 
    // digitalWrite(LED1, HIGH); delay(75);
    // digitalWrite(LED1, LOW); delay(75);
    // digitalWrite(LED2, HIGH); delay(75);
    // digitalWrite(LED2, LOW); delay(75);
 
    // digitalWrite(LED1, HIGH); delay(210);
    // digitalWrite(LED1, LOW); delay(210);
    // digitalWrite(LED2, HIGH); delay(210);
    // digitalWrite(LED2, LOW); delay(210);
    // digitalWrite(LED1, HIGH); delay(210);
    // digitalWrite(LED1, LOW); delay(210);
    // digitalWrite(LED2, HIGH); delay(210);
    // digitalWrite(LED2, LOW); delay(260);
 
 
}
void pattern3(){
   for(int i = 0; i <= 255; i++) {
    // analogWrite(LED1, i);
    delay(1);
  }
  for(int i = 255; i >= 0; i--){
    // analogWrite(LED1, i);
    delay(1);
  }
   for(int i = 0; i <= 255; i++) {
    // analogWrite(LED2, i);
    delay(1);
  }
  for(int i = 255; i >= 0; i--){
    // analogWrite(LED2, i);
    delay(1);
  }
}
void pattern4(){
 
  // digitalWrite(LED1, HIGH); delay(75);
  // digitalWrite(LED1, LOW); delay(75);
  // digitalWrite(LED2, HIGH); delay(75);
  // digitalWrite(LED2, LOW); delay(75);
 
  // digitalWrite(LED1, HIGH); delay(75);
  // digitalWrite(LED1, LOW); delay(75);
  // digitalWrite(LED2, HIGH); delay(75);
  // digitalWrite(LED2, LOW); delay(75);
 
for(int i = 0; i <= 255; i++) {
    // analogWrite(LED1, i);
    delay(1);
  }
  for(int i = 255; i >= 0; i--){
    // analogWrite(LED1, i);
    delay(1);
  }
   for(int i = 0; i <= 255; i++) {
    // analogWrite(LED2, i);
    delay(3);
  }
  for(int i = 255; i >= 0; i--){
    // analogWrite(LED2, i);
    delay(3);
  }
 
}
void pattern5(){
  for(int i = 0; i <= 255; i++) {
    // analogWrite(LED1, i);
    // analogWrite(LED2, i);
    delay(6);
  }
 
 
}
void pattern6(){
    for(int i = 255; i >= 0; i--){
      //  analogWrite(LED1, i);
      //  analogWrite(LED2, i);
        delay(9);
    }
}
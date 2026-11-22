/*
   Arduino Bluetooth Car with Front and Back Light Control
   Updated by: Your Name
*/

#include <AFMotor.h>

// Motor initialization
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

// LED pins for front and back lights
const int frontLightPin = 9;
const int backLightPin = 10;

int val;
int speedValue = 255;  // Default speed

void setup() {
    Serial.begin(9600);  // Set baud rate for Bluetooth
    pinMode(frontLightPin, OUTPUT);
    pinMode(backLightPin, OUTPUT);
    stopCar();  // Initialize with motors stopped
}

void loop() {
    if (Serial.available() > 0) {
        val = Serial.read();

        switch (val) {
            case 'F': forward(); break;
            case 'B': back(); break;
            case 'L': left(); break;
            case 'R': right(); break;
            case 'I': topright(); break;
            case 'J': topleft(); break;
            case 'K': bottomright(); break;
            case 'M': bottomleft(); break;
            case 'A': autoLight(); break;
            case 'X': frontLight(); break;
            case 'Y': backLight(); break;
            case 'T': stopCar(); break;
            default: break;
        }
    }
}

/* ====== Car Movement Functions ====== */
void forward() {
    motor1.setSpeed(speedValue);
    motor1.run(FORWARD);
    motor2.setSpeed(speedValue);
    motor2.run(BACKWARD);
    motor3.setSpeed(speedValue);
    motor3.run(BACKWARD);
    motor4.setSpeed(speedValue);
    motor4.run(FORWARD);
}

void back() {
    motor1.setSpeed(speedValue);
    motor1.run(BACKWARD);
    motor2.setSpeed(speedValue);
    motor2.run(FORWARD);
    motor3.setSpeed(speedValue);
    motor3.run(FORWARD);
    motor4.setSpeed(speedValue);
    motor4.run(BACKWARD);
}

void left() {
    motor1.setSpeed(speedValue);
    motor1.run(BACKWARD);
    motor2.setSpeed(speedValue);
    motor2.run(FORWARD);
    motor3.setSpeed(speedValue);
    motor3.run(BACKWARD);
    motor4.setSpeed(speedValue);
    motor4.run(FORWARD);
}

void right() {
    motor1.setSpeed(speedValue);
    motor1.run(FORWARD);
    motor2.setSpeed(speedValue);
    motor2.run(BACKWARD);
    motor3.setSpeed(speedValue);
    motor3.run(FORWARD);
    motor4.setSpeed(speedValue);
    motor4.run(BACKWARD);
}

void topleft() {
    motor1.setSpeed(speedValue);
    motor1.run(FORWARD);
    motor2.setSpeed(speedValue);
    motor2.run(BACKWARD);
    motor3.setSpeed(speedValue / 2);
    motor3.run(BACKWARD);
    motor4.setSpeed(speedValue / 2);
    motor4.run(FORWARD);
}

void topright() {
    motor1.setSpeed(speedValue / 2);
    motor1.run(FORWARD);
    motor2.setSpeed(speedValue / 2);
    motor2.run(BACKWARD);
    motor3.setSpeed(speedValue);
    motor3.run(BACKWARD);
    motor4.setSpeed(speedValue);
    motor4.run(FORWARD);
}

void bottomleft() {
    motor1.setSpeed(speedValue);
    motor1.run(BACKWARD);
    motor2.setSpeed(speedValue);
    motor2.run(FORWARD);
    motor3.setSpeed(speedValue / 2);
    motor3.run(FORWARD);
    motor4.setSpeed(speedValue / 2);
    motor4.run(BACKWARD);
}

void bottomright() {
    motor1.setSpeed(speedValue / 2);
    motor1.run(BACKWARD);
    motor2.setSpeed(speedValue / 2);
    motor2.run(FORWARD);
    motor3.setSpeed(speedValue);
    motor3.run(FORWARD);
    motor4.setSpeed(speedValue);
    motor4.run(BACKWARD);
}

void stopCar() {
    motor1.setSpeed(0);
    motor1.run(RELEASE);
    motor2.setSpeed(0);
    motor2.run(RELEASE);
    motor3.setSpeed(0);
    motor3.run(RELEASE);
    motor4.setSpeed(0);
    motor4.run(RELEASE);
    digitalWrite(frontLightPin, LOW);
    digitalWrite(backLightPin, LOW);
}

/* ====== Light Control Functions ====== */
void frontLight() {
    digitalWrite(frontLightPin, HIGH);
    digitalWrite(backLightPin, LOW);
}

void backLight() {
    digitalWrite(frontLightPin, LOW);
    digitalWrite(backLightPin, HIGH);
}

void autoLight() {
    // Lights turn on/off based on movement
    if (val == 'F' || val == 'I' || val == 'J') {
        digitalWrite(frontLightPin, HIGH);
        digitalWrite(backLightPin, LOW);
    } else if (val == 'B' || val == 'K' || val == 'M') {
        digitalWrite(frontLightPin, LOW);
        digitalWrite(backLightPin, HIGH);
    } else {
        digitalWrite(frontLightPin, LOW);
        digitalWrite(backLightPin, LOW);
    }
}

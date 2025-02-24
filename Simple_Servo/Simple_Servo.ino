#include <Servo.h>

Servo myServo;  // Servo-Objekt erstellen

void setup() {
  myServo.attach(11);  // Servo an Pin 11 anschließen
}

void loop() {
  myServo.write(0);   // Servo auf 0° stellen
  delay(1000);        // 1 Sekunde warten
  myServo.write(90);  // Servo auf 90° stellen
  delay(1000);        // 1 Sekunde warten
  myServo.write(180); // Servo auf 180° stellen
  delay(1000);        // 1 Sekunde warten
}
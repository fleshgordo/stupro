/*
  Dieser Sketch steuert einen DC-Motor über das Quad DC Motor Driver Shield for Arduino.
  Der Motor wird vorwärts und rückwärts mit einer Geschwindigkeit von 100 (PWM-Wert) bewegt.
  Es wird alle 2 Sekunden zwischen vorwärts und rückwärts gewechselt.

  Verkabelung:
  - Motoranschlüsse: Schließe den Motor an die entsprechenden Pins des Motor Shields an (M1).
  - Motor Shield Pins:
    - E1 (Pin 3): Steuert die Geschwindigkeit des Motors (über PWM).
    - M1 (Pin 4): Steuert die Drehrichtung des Motors (vorwärts oder rückwärts).

  - Das Motorshield muss mit einer externen Stromquelle für den Motor versorgt werden, während der Arduino selbst über USB oder ein separates Netzteil mit Strom versorgt wird.
*/
const int E1 = 3;  // Motor1 Speed
const int M1 = 4;  // Motor1 Direction

// die restlichen Definitionen für die anderen Motoranschlüsse M2, M3, M4
//const int E2 = 11; // Motor2 Speed
//const int M2 = 12; // Motor2 Direction
//const int E3 = 5;  // Motor3 Speed
//const int M3 = 8;  // Motor3 Direction
//const int E4 = 6;  // Motor4 Speed
//const int M4 = 7;  // Motor4 Direction

void M1_advance(char Speed)  ///<Motor1 Advance
{
  digitalWrite(M1, LOW);  // Setzt die Drehrichtung auf vorwärts
  analogWrite(E1, Speed); // Setzt die Geschwindigkeit des Motors (0-255)
}

void M1_back(char Speed)  ///<Motor1 Back off
{
  digitalWrite(M1, HIGH); // Setzt die Drehrichtung auf rückwärts
  analogWrite(E1, Speed); // Setzt die Geschwindigkeit des Motors (0-255)
}

void setup() {
  pinMode(E1, OUTPUT); // Setzt den E1 Pin als Ausgang (PWM Pin für Geschwindigkeit)
  pinMode(M1, OUTPUT); // Setzt den M1 Pin als Ausgang (Steuerung der Richtung)
}

void loop() {
  M1_advance(100);  // Motor vorwärts mit 100 (PWM)
  delay(2000);      // Warten für 2 Sekunden
  M1_back(100);     // Motor rückwärts mit 100 (PWM)
  delay(2000);      // Warten für 2 Sekunden
}
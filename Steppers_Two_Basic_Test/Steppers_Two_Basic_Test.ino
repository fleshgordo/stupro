/*
   Simple demo with DRV8255 driver on CNC shield

   Connect STEP, DIR as indicated!
   Driverslots X, Y, Z on the CNC shield can be used

   In this demo driver chip is in slot X (pin 5, 2)

   Adapted 2022/2023 by Gordan Savicic
   based on Copyright (C)2015-2017 Laurentiu Badea

   This file may be redistributed under the terms of the MIT license.
   A copy of this license has been included with this distribution in the file LICENSE.

*/
#include <Arduino.h>
#include "BasicStepperDriver.h"

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define RPM 120

// Since microstepping is set externally, make sure this matches the selected mode
// Set the jumper to middle position when using MICROSTEPS 4, no jumper = MICROSTEPS 1
// 1=full step, 2=half step etc.
#define MICROSTEPS 4

// Driver in CNC shield X
#define DIR_X 5
#define STEP_X 2

// Driver in CNC shield Y
#define DIR_Y 6
#define STEP_Y 3

// Driver in CNC shield Z
#define DIR_Z 7
#define STEP_Z 4

// Define the pin for enable/disable functionality
#define SLEEP 8

// Initialize the driver(s)
BasicStepperDriver stepperX(MOTOR_STEPS, DIR_Y, STEP_Y, SLEEP);
BasicStepperDriver stepperY(MOTOR_STEPS, DIR_X, STEP_X, SLEEP);

void setup() {
  // Pass some config to the instances and begin
  stepperX.begin(RPM, MICROSTEPS);
  //stepperX.setSpeedProfile(stepper.LINEAR_SPEED);
  
  // if using enable/disable on ENABLE pin (active LOW) instead of SLEEP uncomment next line
  stepperX.setEnableActiveState(LOW);

  stepperY.begin(RPM, MICROSTEPS);

  // if using enable/disable on ENABLE pin (active LOW) instead of SLEEP uncomment next line
  stepperY.setEnableActiveState(LOW);
}

void loop() {
  // energize coils
  stepperX.enable();
  stepperY.enable();

  // Moving motor one full revolution using the degree notation
  stepperX.rotate(360);
  stepperY.rotate(360);

  // pause and allow the motor to be moved by hand
  stepperX.disable();
  stepperY.disable();

  delay(2000);  // repeat after 2sec. pause
}
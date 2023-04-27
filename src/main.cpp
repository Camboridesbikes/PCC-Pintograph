#include <Arduino.h>
#include <AccelStepper.h>

const int stepsPerRevolution = 2038;

AccelStepper _Stepper1(AccelStepper::FULL4WIRE, 8, 9, 10, 11);
AccelStepper _Stepper2(AccelStepper::FULL4WIRE, 4, 5, 6, 7);

int potPin1 = A0;
int potValue1 = 0;

int potPin2 = A1;
int potValue2 = 0;

int speed1;
int speed2;

long timestamp1;
long timestamp2;

void setup() {
  Serial.begin(9600); 

  _Stepper1.setMaxSpeed(350);
  _Stepper1.setAcceleration(100);
  _Stepper1.setSpeed(200);

  _Stepper2.setMaxSpeed(350);
  _Stepper2.setAcceleration(100);
  _Stepper2.setSpeed(100);

  timestamp1 = millis();
  timestamp2 = millis();
}

void loop() {
  if (timestamp1 + 100 < millis())
  {
    potValue1 = analogRead(potPin1);
    speed1 = map(potValue1, 0, 1023, 100, 350);

    Serial.print("Speed 1: " + String(speed1) + "\n");

    _Stepper1.setSpeed(speed1);
    timestamp1 = millis();
    

  }

  if (timestamp2 + 100 < millis())
  {
    potValue2 = analogRead(potPin2);
    speed2 = map(potValue2, 0, 1023, 100, 350);

    Serial.print("Speed2: " + String(speed2) + "\n");


    _Stepper2.setSpeed(speed2);
    timestamp2 = millis();
  }

  _Stepper1.runSpeed();
  _Stepper2.runSpeed();



}


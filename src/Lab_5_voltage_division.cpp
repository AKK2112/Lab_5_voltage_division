/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "d:/Labs/Lab_5_voltage_division/src/Lab_5_voltage_division.ino"
void setup();
void loop();
#line 1 "d:/Labs/Lab_5_voltage_division/src/Lab_5_voltage_division.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

int sensorValue = 0;

void setup() {
  pinMode(A5, INPUT);
  pinMode(D8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor
  sensorValue = analogRead(A5);
  // print the sensor reading so you know its range
  Serial.println(sensorValue);
   // map the sensor reading to a range for the LED
  max(3485, sensorValue);
  min(0, sensorValue);
  analogWrite(D8, map(sensorValue, 0, 1023, 0, 255));

}
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
uint16_t maxValue = 0;
uint16_t minValue = 4095;

void setup() {
  pinMode(A5, INPUT);
  pinMode(D8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the light sensor
  sensorValue = analogRead(A5);
  // use the serial monitor to identify the max and min range
  Serial.println(sensorValue);
   // turn the led on to a brightness specified from the map function.
  maxValue = max(maxValue, sensorValue);
  minValue = min(minValue, sensorValue);
  analogWrite(D8, map(sensorValue, minValue, maxValue, 0, 255));
  //I had delay in before to find the max and min ranges in the serial monitor, 
  //but I removed it because it would delay the led and looked weird.
  //No delay significantly decreases the delay in the change of brightness and looks much smoother overall.
}
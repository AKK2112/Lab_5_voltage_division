SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

int sensorValue = 0;

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
  max(3485, sensorValue);
  min(0, sensorValue);
  analogWrite(D8, map(sensorValue, 0, 1023, 0, 255));
  //I had delay in before to find the max and min ranges in the serial monitor, 
  //but I removed it because it would delay the led and looked weird.
  //No delay significantly decreases the delay in the change of brightness and looks much smoother overall.
}
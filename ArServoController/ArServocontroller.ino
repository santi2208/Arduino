#include<Servo.h>
Servo servo1;
const int pulsMin = 50;
const int pulsMax = 2300;

void setup() {
  servo1.attach(11, pulsMin, pulsMax);
  Serial.begin(9600);  
}

void loop() {
  Serial.println("0");
  servo1.write(0);
  delay(2000);

  

  Serial.println("180");
  servo1.write(170);
  delay(2000);
}

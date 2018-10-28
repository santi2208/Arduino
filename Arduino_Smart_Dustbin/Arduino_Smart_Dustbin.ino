//viral science
//www.youtube.com/c/viralscience
#include <Servo.h>   //servo library
Servo servo;     
int trigPin = 2;    
int echoPin = 3;   
int servoPin = 9;

long duration, dist, average;   
long aver[3];   //array for average
int minDist = 20;
int gradosMax = 130;
int servoDelayTime = 3500;

void setup() {       
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0);         //close cap on power on
    delay(1000);
    servo.detach();
    Serial.begin(9600);
} 

void measure() {  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  dist = (duration/2) / 29.1;    //obtain distance
  Serial.println(dist);
}

void loop() { 
  for (int i=0;i<=3;i++) 
  {   //average distance
    measure();               
    aver[i]=dist;            
    delay(50);             
  }

  dist=(aver[0]+aver[1]+aver[2]+aver[3])/4; 

  if (dist < minDist) {
    servo.attach(servoPin);
    delay(1);
    servo.write(gradosMax);  
    delay(servoDelayTime); 
    servo.write(0);    
    delay(1000);
    servo.detach();      
  }
}


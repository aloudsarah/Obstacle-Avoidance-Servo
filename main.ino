
#include <Servo.h>

Servo scanServo;

const int trig = 9;
const int echo = 8;
const int servo = 10;
const int led = 12; 

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT); 

  scanServo.attach(servo);
  scanServo.write(90); 
  digitalWrite(led, LOW); 

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH, 25000);
  int distance = (duration == 0) ? 100 : (duration * 0.034 / 2);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
  if (distance > 0 && distance <= 10) {
    digitalWrite(led, HIGH);

    scanServo.write(0);   
    delay(400);
    scanServo.write(180); 
    delay(400);
    scanServo.write(90);   
    delay(200);
  } else {
    digitalWrite(led, LOW);
    scanServo.write(90);
  }

  delay(60);
}


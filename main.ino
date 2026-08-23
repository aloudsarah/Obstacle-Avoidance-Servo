#include <Servo.h>

Servo scanServo;


const int trig = 13;
const int echo = A0;

const int servo = 10;

const int led = 12;

const int leftIn1 = 2;
const int leftIn2 = 3;
const int leftEnable  = 9;

const int rightIn3 = 4;
const int rightIn4 = 5;
const int rightEnable = 6;

const int speed = 200; 

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  pinMode(leftIn1, OUTPUT);
  pinMode(leftIn2, OUTPUT);
  pinMode(leftEnable, OUTPUT);
  pinMode(rightIn3, OUTPUT);
  pinMode(rightIn4, OUTPUT);
  pinMode(rightEnable, OUTPUT);

  scanServo.attach(servo);
  scanServo.write(90);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH, 25000);
  int distance = (duration == 0) ? 100 : (duration * 0.034 / 2);

  if (distance > 0 && distance <= 10) {
    digitalWrite(led, HIGH);

    analogWrite(leftEnable, 0);
    analogWrite(rightEnable, 0);
    digitalWrite(leftIn1, LOW);
    digitalWrite(leftIn2, LOW);
    digitalWrite(rightIn3, LOW);
    digitalWrite(rightIn4, LOW);
    delay(200);

    scanServo.write(0);  
    delay(400);
    scanServo.write(180); 
    delay(400);
    scanServo.write(90);  
    delay(200);

 
    digitalWrite(leftIn1, LOW);
    digitalWrite(leftIn2, HIGH);
    analogWrite(leftEnable, speed);
    digitalWrite(rightIn3, LOW);
    digitalWrite(rightIn4, HIGH);
    analogWrite(rightEnable, speed);
    delay(800);


    digitalWrite(leftIn1, HIGH);
    digitalWrite(leftIn2, LOW);
    analogWrite(leftEnable, speed);
    digitalWrite(rightIn3, LOW);
    digitalWrite(rightIn4, HIGH);
    analogWrite(rightEnable, speed);
    delay(400);

 
    analogWrite(leftEnable, 0);
    analogWrite(rightEnable, 0);
    digitalWrite(leftIn1, LOW);
    digitalWrite(leftIn2, LOW);
    digitalWrite(rightIn3, LOW);
    digitalWrite(rightIn4, LOW);
  } else {

    digitalWrite(led, LOW);

    digitalWrite(leftIn1, HIGH);
    digitalWrite(leftIn2, LOW);
    analogWrite(leftEnable, speed);

    digitalWrite(rightIn3, HIGH);
    digitalWrite(rightIn4, LOW);
    analogWrite(rightEnable, speed);
  }

  delay(50);
}
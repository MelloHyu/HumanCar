#include <AFMotor.h>
#include <Servo.h>
#include<NewPing.h>
#define RIGHT A5
#define LEFT A3
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 100

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

AF_DCMotor Motor2(2,MOTOR12_1KHZ);

AF_DCMotor Motor4(4,MOTOR34_1KHZ);

void setup() {
  Serial.begin(9600);
pinMode(RIGHT, INPUT);
pinMode(LEFT, INPUT);
delay(500);
Serv();
}

void loop() {

  delay(150);
float distance = sonar.ping_cm();

Serial.println(distance);
int Right_Value = digitalRead(RIGHT);
int Left_Value = digitalRead(LEFT);
Serial.println(Right_Value);
Serial.println(Left_Value);

if((Right_Value==1) &&(Left_Value==1)&& (distance>= 12 && distance<=43)){

  Motor2.setSpeed(250);
  Motor2.run(BACKWARD);

  Motor4.setSpeed(250);
  Motor4.run(FORWARD);
}else if((Right_Value==1) && (Left_Value==0)) {

  Motor2.setSpeed(200);
  Motor2.run(BACKWARD);

  Motor4.setSpeed(200);
  Motor4.run(BACKWARD);
}else if((Right_Value==0)&&(Left_Value==1)) {

  Motor2.setSpeed(200);
  Motor2.run(FORWARD);

  Motor4.setSpeed(200);
  Motor4.run(FORWARD);
}else if((Right_Value==1)&&(Left_Value==1)) {

  Motor2.setSpeed(0);
  Motor2.run(RELEASE);

  Motor4.setSpeed(0);
  Motor4.run(RELEASE);
}else if(distance > 1 && distance < 12) {

  Motor2.setSpeed(0);
  Motor2.run(RELEASE);

  Motor4.setSpeed(0);
  Motor4.run(RELEASE);
  }
 }


 
 void Serv()
 {
  int a=90,b=90;
  Servo myservo1;
  myservo1.attach(10);
  myservo1.write(98);

  while(a<=180)
 {
  a++;
  myservo1.write(a);
  delay(50);
 }

 float distance1= sonar.ping_cm();
Serial.println(distance1);
if(distance1>= 12 && distance1<=43)
{
  Motor2.setSpeed(170);
  Motor2.run(BACKWARD); //rotate motor 

  Motor4.setSpeed(170);
  Motor4.run(BACKWARD);
  delay(450);
  Motor2.setSpeed(0);
  Motor2.run(RELEASE);

  Motor4.setSpeed(0);
  Motor4.run(RELEASE);
  }

delay(3000);
while(b>=0)
{
  b--;
  
myservo1.write(b);
delay(50);
}
 distance1= sonar.ping_cm();
Serial.println(distance1);
if(distance1>= 12 && distance1<=43)
{
  Motor2.setSpeed(170);
  Motor2.run(FORWARD);

  Motor4.setSpeed(170);
  Motor4.run(FORWARD);
  delay(450);
  Motor2.setSpeed(0);
  Motor2.run(RELEASE);

  Motor4.setSpeed(0);
  Motor4.run(RELEASE);
  
}

delay(3000);
myservo1.write(98);
 }

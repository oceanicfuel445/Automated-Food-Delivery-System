#include <AFMotor.h>

#define TrigPIN 9
#define EchoPIN 10
#define MOTOR 3
#define redpin 5
#define greenpin 6
#define Speed 170
#define LOW_Speed 85

AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

int distance;

void setup() {
  Serial.begin(9600);
  pinMode(TrigPIN, OUTPUT);
  pinMode(EchoPIN, INPUT);
  pinMode(MOTOR, OUTPUT);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  M1.setSpeed(Speed);
  M2.setSpeed(Speed);
  M3.setSpeed(Speed);
  M4.setSpeed(Speed);
}

void loop() {
  distance = ultrasonic();
  if (distance <= 5)
 {
    Stop();
    digitalWrite(redpin, HIGH);
    digitalWrite(greenpin, LOW);
  } 


else 
{
    digitalWrite(greenpin, HIGH);
    digitalWrite(redpin, LOW);
    forward();
  }
}

int ultrasonic() 
{
  digitalWrite(TrigPIN, LOW);
  delayMicroseconds(4);
  digitalWrite(TrigPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPIN, LOW);
  long duration = pulseIn(EchoPIN, HIGH);
  long cm = duration / 29 / 2;
   //time convert distance
  return cm;
}

void forward() 
{
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}

void Stop()
{
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
}

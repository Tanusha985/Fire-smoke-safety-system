#include <Servo.h>
int gasensor = 5;
int sounder = 9;
int motorpositive = 6;
int motornegative = 7;
int led = 11;
int tempsensor = A0;
Servo flapServo;
void setup()
{
  pinMode(gasensor, INPUT);
  pinMode(tempsensor, INPUT);
  pinMode(motorpositive, OUTPUT);
  pinMode(motornegative, OUTPUT);
  pinMode(sounder, OUTPUT);
  pinMode(led, OUTPUT);
  flapServo.attach(3);
}
void loop()
{
  int adc = analogRead(tempsensor);
  int temp = (adc*500L)/ 1023;
  if (digitalRead(gasensor)==HIGH && temp <134 && temp>1)
  {
    digitalWrite(sounder, LOW);
    flapServo.write(90);
    digitalWrite(motorpositive, HIGH);
    digitalWrite(motornegative, LOW);
    digitalWrite(led, HIGH);
    delay(250);
    digitalWrite(led, LOW);
    delay(250);
  }
  if (digitalRead(gasensor)==HIGH && temp >134)
  {
    digitalWrite(sounder, HIGH);
    flapServo.write(0);
    digitalWrite(motorpositive, LOW);
    digitalWrite(motornegative, LOW);
    digitalWrite(led, HIGH);
    delay(250);
    digitalWrite(led, LOW);
    delay(250);
  }
  else
  
  {
    digitalWrite(sounder, LOW);
    digitalWrite(motorpositive, LOW);
    digitalWrite(motornegative, LOW);
    flapServo.write(90);
    digitalWrite(led, LOW);
  }
}
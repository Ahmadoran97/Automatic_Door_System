#include <Servo.h>
Servo servo;

const int trigPin = 9;
const int echoPin = 8;
float duration;
float distance;

void setup() 
{
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
servo.attach(6);
servo.write(0);
}

void loop() 
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration*.0343)/2; 

Serial.print(distance);
Serial.println(" cm");
delay(100);

if (distance < 15) {servo.write(90);}

else {servo.write(0);}

}

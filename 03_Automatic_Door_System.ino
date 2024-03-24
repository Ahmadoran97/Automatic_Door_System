#include <Servo.h>
Servo servo;

const int trigPin = 10;
const int echoPin = 9;
float duration;
float distance;

void setup() 
{
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
servo.attach(3);
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

servo.write(0);

if (distance < 15) 
{
servo.write(90);
}

else
{
servo.write(0); 
}

}

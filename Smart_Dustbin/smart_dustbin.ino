#include <Servo.h>
#define trig 7
#define echo 6
Servo motor;


void setup() {
  motor.attach(9);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
  

}


void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);

  float zaman = pulseIn(echo,HIGH);
  float cm = zaman/58.2;
  delay(200);
  Serial.println(cm);
  if (cm<30){
    motor.write(0);
    delay(300);
    motor.write(90);
    delay(300);
    motor.write(180);
    
  }
  

}

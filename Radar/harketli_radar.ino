#include <Servo.h>
#define echo 6
#define trig 7
long zaman;
int cm;
Servo motor;

void setup() {
  pinMode (trig,OUTPUT);
  pinMode (echo, INPUT);
  motor.attach(9);
  Serial.begin(9600);

}

void loop() {
  for(int i=15; i<=165; i++){
    motor.write(i);
    delay(20);
    cm=mesafebul();
    Serial.print(i);
    Serial.print(",");
    Serial.print(cm);
    Serial.print(".");
  }
  for(int i=165;i>=15; i--){
    motor.write(i);
    delay(20);
    cm=mesafebul();
    Serial.print(i);
    Serial.print(",");
    Serial.print(cm);
    Serial.print(".");
  }


}


int mesafebul(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  zaman = pulseIn(echo,HIGH);
  float cm =  zaman/58.2 ;
  return cm;

   }

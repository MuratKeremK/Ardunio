#define echo 12
#define trig 13

#define sagmotor1 4
#define sagmotor2 5
#define sagmotorEn 3
#define solmotor1 6
#define solmotor2 7
#define solmotorEn 9

long zaman;
int cm;

void setup() {
  pinMode (trig,OUTPUT);
  pinMode (echo,INPUT);

  pinMode(sagmotor1,OUTPUT);
  pinMode(sagmotor2, OUTPUT);
  pinMode(sagmotorEn,OUTPUT);

  pinMode(solmotor1,OUTPUT);
  pinMode(solmotor2, OUTPUT);
  pinMode(solmotorEn,OUTPUT);

  Serial.begin(9600);
  
}



void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  zaman = pulseIn(echo,HIGH);
  cm = zaman/58;

  Serial.println(cm);

  if(cm<20){
    dur();
    delay(1000);
    sag();
    delay(250);
  }
    else{
      ileri();
    }
 }

 void  ileri(){
  digitalWrite(sagmotor1,HIGH);
  digitalWrite(sagmotor2,LOW);
  analogWrite(sagmotorEn,100);

  digitalWrite(solmotor1,LOW);
  digitalWrite(solmotor2,HIGH);
  analogWrite(solmotorEn,100);
}
void dur(){
  digitalWrite(sagmotor1,LOW);
  digitalWrite(sagmotor2,LOW);
  analogWrite(sagmotorEn,0);

  digitalWrite(solmotor1,LOW);
  digitalWrite(solmotor2,LOW);
  analogWrite(solmotorEn,0);
}
void sag(){
  digitalWrite(sagmotor1,LOW);
  digitalWrite(sagmotor2,LOW);
  analogWrite(sagmotorEn,0);

  digitalWrite(solmotor1,HIGH);
  digitalWrite(solmotor2,LOW);
  analogWrite(solmotorEn,250);
}

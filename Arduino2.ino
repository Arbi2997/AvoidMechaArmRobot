#include <Servo.h>
#define echoPin 34
#define trigPin 2

//Ultrasonik Sensor+Speker
int buzzer = 36;
long duration;
int distance;

//Motor Kanan
int In1 = 23;
int In2 = 24;
int In3 = 25;
int In4 = 26;
int Ena = 22;
int Enb = 27;

//Motor Kiri
int in1 = 29;
int in2 = 30;
int in3 = 31;
int in4 = 32;
int ena = 28;
int enb = 33;

//Speed
int Speed = 1000;

//Mechanical Arm + GigiBiru
//Lengan paling atas (Posisi Servo)
int pin_servo6 = 10;
Servo servo6;

//dibawah Lengan atas
int pin_servo5 = 9;
Servo servo5;

//Lengan putar atas/tengah
int pin_servo4 = 8;
Servo servo4;

//dibawah Lengan putar atas/tengah
int pin_servo3 = 7;
Servo servo3;

//Lengan Tengah
int pin_servo2 = 6;
Servo servo2;

//Lengan putar bawah
int pin_servo1 = 5;
Servo servo1;

int sudut = 0;
int data;

void setup(){
  Serial.begin(9600);
  //Utrasonik Sensor+Speker
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Arm
  servo6.attach(pin_servo6);
  servo5.attach(pin_servo5);
  servo4.attach(pin_servo4);
  servo3.attach(pin_servo3);
  servo2.attach(pin_servo2);
  servo1.attach(pin_servo1);

  //Motor Kanan
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(Ena, OUTPUT);
  pinMode(Enb, OUTPUT);

  //Motor Kiri
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  while(Serial.available()>0){
    data = Serial.read();
    Serial.println(data);   
  
    //Action Arm
    if(data == '1'){
      for(sudut=0; sudut <= 180; sudut +=1){
        servo6.write(sudut);
        delay(15);        
      }
    }
    else if(data == '2'){
      for(sudut=180; sudut >= 0; sudut -=1){
        servo6.write(sudut);
        delay(15);
      }
    }
    else if(data == '3'){
      for(sudut=0; sudut <= 180; sudut += 1){
        servo1.write(sudut);
        delay(15);
      }
    }
    else if(data == '4'){
      for(sudut=180; sudut >= 0; sudut -= 1){
        servo1.write(sudut);
        delay(15);
      }
    }
    else if(data == '5'){
      for(sudut=90; sudut <= 180; sudut += 1){
        servo2.write(sudut);
        delay(15);
      }
    }
    else if(data == '6'){
      for(sudut=180; sudut >= 90; sudut -= 1){
        servo2.write(sudut);
        delay(15);
      }
    }
    else if(data == '7'){
      for(sudut=0; sudut <= 180; sudut += 1){
        servo3.write(sudut);
        delay(15);
      }
    }
    else if(data == '8'){
      for(sudut=150; sudut >= 0; sudut -= 1){
        servo3.write(sudut);
        delay(15);
      }
    }
    else if(data == '9'){
      for(sudut=0; sudut <= 180; sudut += 1){
        servo4.write(sudut);
        delay(15);
      }
    }
    else if(data == 'Q'){
      for(sudut=180; sudut >= 0; sudut -= 1){
        servo4.write(sudut);
        delay(15);
      }
    }
    else if(data == 'W'){
      for(sudut=0; sudut <= 180; sudut += 1){
        servo5.write(sudut);
        delay(15);
      }
    }
    else if(data == 'R'){
      for(sudut=180; sudut >= 0; sudut -= 1){
        servo5.write(sudut);
        delay(15);
      }
    }

    //Untuk Motor
    else if(data == 'w'){   //Maju
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
      digitalWrite(In3, LOW);
      digitalWrite(In4, LOW);
      digitalWrite(Ena, HIGH);
      digitalWrite(Enb, HIGH);
    }
    else if(data == 's') {    //Mundur
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
      digitalWrite(In3, LOW);
      digitalWrite(In4, LOW);
      digitalWrite(Ena, HIGH);
      digitalWrite(Enb, HIGH);
    }
    else if(data == 'd'){   //Kanan
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
      digitalWrite(In3, LOW);
      digitalWrite(In4, LOW);
      digitalWrite(Ena, HIGH);
      digitalWrite(Enb, HIGH);
    }
    else if(data == 'a') {    //Kiri
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
      digitalWrite(In3, LOW);
      digitalWrite(In4, LOW);
      digitalWrite(Ena, HIGH);
      digitalWrite(Enb, HIGH);
    }
    else if(data == 'x') {    //Berhenti
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
      digitalWrite(In3, LOW);
      digitalWrite(In4, LOW);
      digitalWrite(Ena, HIGH);
      digitalWrite(Enb, HIGH);
    }
  }
  if(distance <= 10){    //Paksa Mundur
    digitalWrite(buzzer, HIGH);
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
    digitalWrite(Ena, HIGH);
    digitalWrite(Enb, HIGH);
  }
  else{
    digitalWrite(buzzer, LOW);
  }
}
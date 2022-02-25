#include <Arduino.h>
#include <SmartInput.h>

#define BOT1 14
#define BOT2 15
#define SENSOR1 16
#define SENSOR2 17

#define RELE1 2
#define RELE2 3

#define TEMPO 20000

SmartInput bot1(BOT1);
SmartInput bot2(BOT2);

bool porta_aberta1 = false;
bool porta_aberta2 = false;

unsigned long tempo_abertura1 = 0;
unsigned long tempo_abertura2 = 0;


void setup() {
  

  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
  pinMode(RELE1, OUTPUT);
  pinMode(RELE2, OUTPUT);

  digitalWrite(RELE1, LOW);
  digitalWrite(RELE2, LOW);

  
}

void fechar1() {
  digitalWrite(RELE1, LOW);
  porta_aberta1 = false;
}

void fechar2() {
  digitalWrite(RELE2, LOW);
  porta_aberta2 = false;
}

void loop() {
  if(bot1.read()){
    digitalWrite(RELE1, HIGH);
    tempo_abertura1 = millis();
  }
  if(bot2.read()){
    digitalWrite(RELE2, HIGH);
    tempo_abertura2 = millis();
  }

  if(millis() - tempo_abertura1 > TEMPO){
    fechar1();
  }
  if(millis() - tempo_abertura2 > TEMPO){
    fechar2();
  }

  if(digitalRead(SENSOR1) == HIGH && porta_aberta1 == true){
    fechar1();
  }

  if(digitalRead(SENSOR2) == HIGH && porta_aberta2 == true){
    fechar2();
  }
  // put your main code here, to run repeatedly:
}
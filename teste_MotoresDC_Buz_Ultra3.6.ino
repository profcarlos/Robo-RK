/* Sketch:   teste_MotoresDC_3.5
   Objetivo: movimentar RK com comandos simples: mover(), virar()
             e acionando atuadores: Buzzer e LED RGB
   Por:      Prof. Cláudio
   Em:       29.10.2018 - IFG - Campus Goiânia                    */

#include "Rkmotor.h"       // comandos de movimentação do Rk
#include "Rkbuzledultra.h" // comandos dos atuadores: Buzzer e LED RGB

void setup() {
  pinMode(TRIG,OUTPUT); pinMode(ECHO,INPUT);
  pinMode(BUZ, OUTPUT); pinMode(VERM,OUTPUT); 
  pinMode(AZUL,OUTPUT); pinMode(VERD,OUTPUT); 
  digitalWrite(VERM,HIGH); digitalWrite(VERD,HIGH); 
  digitalWrite(AZUL,HIGH); digitalWrite(BUZ, LOW);
  pinMode(MA1, OUTPUT); pinMode(MA2, OUTPUT);
  pinMode(MB1, OUTPUT); pinMode(MB2, OUTPUT);
  pinMode(IP1, INPUT_PULLUP); pinMode(IP2, INPUT_PULLUP);
  pararMotor('*');                                                // desliga ambos motores
  Serial.begin(9600);
  Serial.println("RK - v.1.0 Out/2018\n");
  furosA = furosB = 0;
  attachInterrupt(digitalPinToInterrupt(IP1), motorA, RISING);    // interrupção gerada pelo Encoder do motor 'A'
  attachInterrupt(digitalPinToInterrupt(IP2), motorB, RISING);    // interrupção gerada pelo Encoder do motor 'B'
}

void loop() {
  apitar(0.1);              // Passo A
  if (ultrassom() > 25)  
    mover(25, NORMAL);
  else {
    pararMotor('*');
    apitar(0.5);
    fim();
  }
}

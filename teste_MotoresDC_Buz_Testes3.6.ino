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
int teste, cont = 0;
void loop() {
  
  Serial.println("Selecione o teste:");
  Serial.println("0 - Teste mover frente");
  Serial.println("1 - Teste mover atrás");
  Serial.println("2 - Teste virar 90 graus");
  Serial.println("3 - Teste virar -90 graus");
  Serial.println("4 - Teste apito");
  Serial.println("5 - Teste LED");
  Serial.println("6 - Teste sensor Ultrassom");
  Serial.println("7 - Teste sensor Infravermelho direito");
  Serial.println("8 - Teste sensor Infravermelho erquerdo");
  Serial.println("Digite o teste a ser realizado.");
  Serial.println("...............................");
  while(Serial.available() == 0);
  teste = Serial.read();
  switch(teste-48){
    case 0:
            Serial.println("O robô Rk vai mover 30 cm para frente em velocidade normal");
            mover(30, NORMAL);
            break;
    case 1:
            Serial.println("O robo Rk vai mover 30 cm para trás em velocidade normal");
            mover(-30, NORMAL);
            break;
    case 2:
            Serial.println("O robo Rk vai virar 90 graus em velocidade normal");
            virar(90);
            break;
    case 3:
            Serial.println("O robo Rk vai virar -90 graus em velocidade normal");
            virar(-90);
            break;
    case 4:
            Serial.println("O robo Rk vai apitar duas vezes");
            apitar(0.5);
            esperar(0.5);
            apitar(0.5);
            break;
    case 5:
            cont = 0;
            do{
              Serial.println("O robo Rk vai piscar cada LED de uma vez [vermelho, verde, azul] [5 vezes]");
              led(VERD, DESLIGA);
              led(AZUL, DESLIGA);
              led(VERM,LIGA);
              esperar(1);
              led(VERD,LIGA);
              led(VERM, DESLIGA);
              esperar(1);
              led(AZUL,LIGA);
              led(VERD, DESLIGA);
              esperar(1);
              led(AZUL, DESLIGA);
              cont += 1;
            }while(cont < 5);
            break;
    case 6:
            cont = 0;
            Serial.println("O robo Rk vai testar o sensor ultrassom [10 vezes]");
            do{
              Serial.println(ultrassom());
              esperar(1);
              cont += 1;
            }while(cont < 10);
            break;
    default:
             Serial.println("Esse teste não existe");
             break;
          
  }
  delay(1000);          
}


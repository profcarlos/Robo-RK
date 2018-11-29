// Teste de variação de velocidade do robô móvel com servomotor

#include <Servo.h>

Servo servoA;
Servo servoB;

void setup() {
  // put your setup code here, to run once:
  servoA.attach(6);
  servoB.attach(9);
  Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Dois motores parados
  //servoA.writeMicroseconds(1500);
  //servoB.writeMicroseconds(1500);
  //Para trás 
  //servoA.writeMicroseconds(1000);
  //servoB.writeMicroseconds(2000);
  // Para frente rapido

  Serial.println("rapido");
  servoA.writeMicroseconds(1600);
  servoB.writeMicroseconds(1400);
  // Para frente medio
    delay(5000);
  Serial.println("medio");
  servoA.writeMicroseconds(1575);
  servoB.writeMicroseconds(1425);
  // Para frente realmente lento
  delay(5000);
  Serial.println("lento");
  servoA.writeMicroseconds(1550);
  servoB.writeMicroseconds(1450);
  // Para frente bem lentim
  delay(5000);
  Serial.println("lentim");
  servoA.writeMicroseconds(1525);
  servoB.writeMicroseconds(1475);
  delay(5000);
  Serial.println("parado");
  servoA.writeMicroseconds(1500);
  servoB.writeMicroseconds(1500);
  while(1);
}

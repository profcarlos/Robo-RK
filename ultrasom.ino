//Projeto: Robo RK pr
// Programa: Código do sensor de ultrasom SRF04

#define TRIGGER 4
#define ECHO    5 
float distancia = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
}

float ultrasom(){

  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIGGER, LOW);
  // pulseIn(pin, value, timeout)
  // Tempo dos 8 pulsos de 40 KHz é 200us
  return pulseIn(ECHO, HIGH, 36000)/58;
  
}
 
void loop()
{
  Serial.println(ultrasom());
  delay(1000);
}

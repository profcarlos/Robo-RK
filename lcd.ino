#include <LiquidCrystal.h> // include a library headfile
// LiquidCrystal display with:
// rs on pin 10
// rw on pin 11
// enable on pin 12
// d4, d5, d6, d7 on pins 13, 14, 15, 16
LiquidCrystal lcd(10, 11, 12, 13, 14, 15, 16);

#define LDR A5
int sens = 0;

void setup()
{
lcd.begin(16,2);
lcd.clear();//clears the LCD and positions the cursor in the upper-left corner
lcd.print("hello, world!");// Print a message to the LCD.
lcd.setCursor(2,1); // set to the 3th column and 2nd row
lcd.print("Seeedstudio");// Print a message to the LCD.
Serial.begin(9600);
Serial.println("Inicializando");
delay(1000);
}
void loop()
{
  sens = analogRead(LDR);
  Serial.println(sens);
  lcd.setCursor(2,1);
  if(sens < 500)
    lcd.print("Escuro     ");
  else
    lcd.print("Claro      ");
  delay(1000);
}

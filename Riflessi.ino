#include <LiquidCrystal.h>

#define LED 13
#define PULSANTE 11
#define BUZZER 12
int buzzerPin = 12;
int premuto = 0;
int tempoIniziale = 0;
int tempoFinale = 0;
LiquidCrystal lcd(7,6,5,4,3,2);
void setup() {
   pinMode(LED, OUTPUT);
   pinMode(PULSANTE, INPUT);
   digitalWrite(LED, LOW);
   pinMode(BUZZER,OUTPUT);
   randomSeed(analogRead(0));
   lcd.begin(16,2);
   
   riflessiVisivi();
   riflessiSonori();
}

void riflessiVisivi(){
  int tempoVisivo=random(2000,5000);
  delay(tempoVisivo);
  digitalWrite(LED, HIGH);
  tempoIniziale = millis();
  while (premuto == 0) {
    premuto = digitalRead(PULSANTE);
     if (premuto == HIGH) {
       tempoFinale = millis();
       digitalWrite(LED, LOW);
     }
   }
   premuto = 0;
   lcd.setCursor(0,0);
  int ciao= tempoFinale - tempoIniziale;
   lcd.print(ciao); lcd.print("ms");
   if(ciao>1000){
    lcd.print(" Bocciato");
      }
      else{
        lcd.print(" Promosso");
        }
}

void riflessiSonori(){
  int tempoSonoro=random(2000, 5000);
  delay(tempoSonoro);
   tone(BUZZER, 300,5000);
   tempoIniziale=millis();
   while(premuto==0){
    premuto = digitalRead(PULSANTE);
     if (premuto == HIGH) {
       tempoFinale = millis();
       noTone(BUZZER);
     }
   }
   premuto = 0;
   lcd.setCursor(0,1);
   int ciao= tempoFinale - tempoIniziale;
   lcd.print(ciao);lcd.print("ms");
   if(ciao>1000){
    lcd.print(" Bocciato");
      }
      else{
        lcd.print(" Promosso");
        }
} 





void loop() {
}

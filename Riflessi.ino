#include <LiquidCrystal.h>

#define LED 12
#define PULSANTE 10
int buzzerPin = 11;
int premuto = 0;
int tempoIniziale = 0;
int tempoFinale = 0;
LiquidCrystal lcd(2,3,4,5,6,7);
void setup() {
   pinMode(LED, OUTPUT);
   pinMode(PULSANTE, INPUT);
   digitalWrite(LED, LOW);
   pinMode(7,OUTPUT);
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
   lcd.print(ciao);
}
void riflessiSonori(){
  int tempoSonoro=random(2000, 5000);
  delay(tempoSonoro);
   tone(7, 300,5000);
   tempoIniziale=millis();
   while(premuto==0){
    premuto = digitalRead(PULSANTE);
     if (premuto == HIGH) {
       tempoFinale = millis();
       noTone(buzzerPin);
     }
   }
   premuto = 0;
   lcd.setCursor(0,1);
   int ciao= tempoFinale - tempoIniziale;
   lcd.print(ciao);
} 





void loop() {
}

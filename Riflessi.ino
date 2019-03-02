#define LED 8
#define PULSANTE 6
int premuto = 0;
int tempoPrecedente = 0;
int nuovoTempo = 0;

void setup() {
   pinMode(LED, OUTPUT);
   pinMode(PULSANTE, INPUT);
   digitalWrite(LED, LOW);
   Serial.begin(9600);
   randomSeed(analogRead(0));

   
}

void loop() {
  Serial.println("Durata tempo attesa visivo");
  while(Serial.available()==0) {} 
  int tempoVisivo=random(2500,5000);
  Serial.readString();
  Serial.println(tempoVisivo);

  
   delay(tempoVisivo);
   digitalWrite(LED, HIGH);
   tempoPrecedente = millis();
   while (premuto == 0) {
     premuto = digitalRead(PULSANTE);
     if (premuto == HIGH) {
       nuovoTempo = millis();
       digitalWrite(LED, LOW);
     }
   }
   premuto = 0;
   Serial.print("Tempo (ms): ");
   Serial.println(nuovoTempo - tempoPrecedente);

}

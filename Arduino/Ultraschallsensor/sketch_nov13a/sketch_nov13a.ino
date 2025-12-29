// Pin für den Sender
int SENDEN = 7;

// Pin für das vom Objekt reflektierte Signal
int ECHO = 6;

// Variable für die Speicherung der Entfernung
long Entfernung = 0;

void setup() 
{
  pinMode(SENDEN, OUTPUT);
  pinMode(ECHO, INPUT);

  // Seriellen Monitor starten
  Serial.begin(9600);
}

void loop() 
{
  // Sender kurz ausschalten um Störungen des Signal zu vermeiden
  digitalWrite(SENDEN, LOW);
  delay(5);

  // Signal für 10 Micrsekunden senden, danach wieder ausschalten
  digitalWrite(SENDEN, HIGH);
  delayMicroseconds(10);
  digitalWrite(SENDEN, LOW);

  // pulseIn -> Zeit messen, bis das Signal zurückkommt
  long Zeit = pulseIn(ECHO, HIGH);

  // Entfernung in cm berechnen
  // Zeit/2 -> nur eine Strecke
  Entfernung = (Zeit / 2) * 0.03432;
  //delay(500);

  // nur Entfernungen < 100 anzeigen
  // Messdaten anzeigen
    Serial.print("Entfernung in cm: ");
    Serial.println(Entfernung);
  if (Entfernung < 30 && Entfernung > 10) 
  {
    tone(8, 1000);
    delay(50);
    noTone(8);
    delay(50);
    tone(8, 1000);
    delay(50);
    noTone(8);
  }
   if (Entfernung < 20) 
  {
    tone(8, 1000);
    
  }
}

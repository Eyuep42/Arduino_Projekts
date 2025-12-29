// Pins für L293D
int enable1 = 10;
int enable2 = 11;  
int input1 = 8;
int input2 = 9;
int input3 = 5;
int input4 = 6;

// Sonstige Features
int buzzer = 2;
int statusLed = 1;

// Abstand
int SENDEN = 4;
int ECHO = 3;

long Entfernung = 0;

bool rueckwaerts = false;
void setup() {
  // Setze die Motorsteuerungspins als Ausgänge
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Abstand Vorne 
  pinMode(SENDEN, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
}

void loop() {
  

  // Geschwindigkeit mittel
  analogWrite(enable1, 255);
  analogWrite(enable2, 255);

  messen();
  
  
  
 
}

// Funktion für vorwärts fahren 
void fahrenVorwaerts() { 
  digitalWrite(input1, HIGH); 
  digitalWrite(input2, LOW); 
  digitalWrite(input3, HIGH);  
  digitalWrite(input4, LOW);
  rueckwaerts = false;
  } 
  // Funktion für rückwärts fahren 
  void fahrenRueckwaerts() { 
    digitalWrite(input1, LOW); 
    digitalWrite(input2, HIGH); 
    digitalWrite(input3, LOW); 
    digitalWrite(input4, HIGH);
    rueckwaerts = true;
    } 
  void drehen() { 
    digitalWrite(input1, HIGH); 
    digitalWrite(input2, LOW); 
    digitalWrite(input3, LOW); 
    digitalWrite(input4, LOW);
    rueckwaerts = false;
    tone(buzzer, 1000);
    delay(2000);
    noTone(buzzer);
    delay(1000);
  }
    // Funktion für stoppen 
    void stoppen() { 
      digitalWrite(input1, LOW); 
      digitalWrite(input2, LOW); 
      digitalWrite(input3, LOW); 
      digitalWrite(input4, LOW);
      rueckwaerts = false; 
    }

    void messen() {
        // Sender kurz ausschalten um Störungen des Signal zu vermeiden digitalWrite(SENDEN, LOW); delay(5);
        // Signal für 10 Micrsekunden senden, danach wieder ausschalten
        digitalWrite(SENDEN, HIGH);
        delayMicroseconds(10);
        digitalWrite(SENDEN, LOW);
        // pulseIn -> Zeit messen, bis das Signal zurückkommt
        long Zeit = pulseIn(ECHO, HIGH);
        // Entfernung in cm berechnen
        // Zeit/2 -> nur eine Strecke
        Entfernung = (Zeit / 2) * 0.03432;
        // nur Entfernungen < 100 anzeigen
        // Messdaten anzeigen
        Serial.print("Entfernung in cm: ");
        Serial.println(Entfernung);

        if (Entfernung <= 20) {
          drehen();
        }

        if (Entfernung > 20) {
            fahrenVorwaerts();
        }
    }

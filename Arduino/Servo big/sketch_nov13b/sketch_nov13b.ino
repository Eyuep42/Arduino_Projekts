// Pins für L293D
int enable1 = 10;
int enable2 = 11;
int input1 = 8;
int input2 = 9;
int input3 = 5;
int input4 = 6;

int buzzer = 4;
void setup() {
  // Setze die Motorsteuerungspins als Ausgänge
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);
  pinMode(buzzer, OUTPUT); 
}

void loop() {
  // Geschwindigkeit mittel
  analogWrite(enable1, 180);
  analogWrite(enable2, 180);
  
  // Vorwärts
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  digitalWrite(input3, HIGH);
  digitalWrite(input4, LOW);
  delay(2000);
  // Drehen
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  digitalWrite(input3, LOW);
  digitalWrite(input4, HIGH);
  delay(2000);
 

  delay(1000);        // 1 sec Pause
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  digitalWrite(input3, LOW);
  digitalWrite(input4, HIGH);
  digitalWrite(buzzer,HIGH); // Ton an
   // Rückwärts
  tone(buzzer, 1000); // Sende 1KHz Tonsignal

  delay(500);        // 1 sec Pause

  noTone(buzzer);     // Ton stoppen
 
  delay(2000);

  // Stop
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  digitalWrite(input3, LOW);
  digitalWrite(input4, LOW);
  delay(2000);
}

void setup() {
   pinMode(13, OUTPUT); // Pin 13 wird als Output Deklariert
   pinMode(12, OUTPUT); // Pin 12 wird als Output Deklariert
   pinMode(11, OUTPUT); // Pin 11 wird als Output Deklariert
}

void loop() {
  digitalWrite(11, HIGH); // Pin 11 wird aktiviert
   delay(1000); // Pogramm wartet eine sekunde
   digitalWrite(11, LOW); // Pin 11 wird deaktiviert
  digitalWrite(12, HIGH); // Pin 12 wird aktiviert
   delay(1000); // Pogramm wartet eine sekunde
   digitalWrite(12, LOW); // Pin 12 wird deaktiviert
  digitalWrite(13, HIGH); // Pin 13 wird aktiviert
   delay(1000); // Pogramm wartet eine sekunde
  digitalWrite(13, LOW); // Pin 13 wird deaktiviert
}

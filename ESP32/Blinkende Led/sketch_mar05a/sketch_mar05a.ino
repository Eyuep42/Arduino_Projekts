void setup() {
   pinMode(2, OUTPUT); // Pin 2 wird als Output ausgewählt
}

void loop() {
  digitalWrite(2, HIGH); // Pin 2 wird aktiviert
  delay(1000); // Programm wartet eine Sekunde
  digitalWrite(2, LOW); // Pin 2 wird deaktiviert
  delay(1000); // Programm wartet eine Sekunde
}

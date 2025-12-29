void setup() {
  pinMode(A0, INPUT); // Der Analoge Pin A0 wird als Input definiert
   Serial.begin(9600); // Übertragungsrate wird definiert
}
void loop() {
    int wert = analogRead(A0); // Es wird der wert A0 gelesen und alt integer wert gespeichert
    Serial.println(wert); // Wert wird in der Console ausgegeben
}

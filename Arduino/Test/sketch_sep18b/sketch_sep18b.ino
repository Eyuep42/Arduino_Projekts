void setup() {
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 digitalWrite(9, LOW);
 int wert = digitalRead(9);
 Serial.println(wert);
}

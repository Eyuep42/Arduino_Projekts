void setup() {
  Serial.begin(9600);

}

void loop() {
  for(int zahl=0;zahl<=10;zahl++) {
    if (zahl % 2 == 0) {
      Serial.println(zahl);
    }
  }
}

  int wert = 0;
  double voltage = 0;
  double tempC = 0;
void setup() {
  pinMode(26, INPUT);
  Serial.begin(9600);
  
}

void loop() {
 wert = analogRead(26);
 voltage = (wert / 4096.0) * 3300;
 tempC = (voltage - 500) * 0.1;

 
 Serial.println(tempC);

}

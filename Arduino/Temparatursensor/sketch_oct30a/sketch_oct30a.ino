 int wert = 0;
 double voltage = 0;
 double tempC = 0;
void setup() {
  Serial.begin(9600);
  
}

void loop() {
 wert = analogRead(A0);
 voltage = (wert / 1024.0) * 5000; 
 tempC = (voltage - 500) * 0.1;

 
 Serial.println(tempC);

}

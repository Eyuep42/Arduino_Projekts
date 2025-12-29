int counter = 0;

void setup() {
pinMode(7, INPUT);
pinMode(9, INPUT);

pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(10, OUTPUT);

Serial.begin(9600);
}

void loop() {
int wertDown = digitalRead(7);
int wert = digitalRead(9);
 Serial.println(wertDown);

if (wertDown == 0) {
  counter = 0;
 
  
  
  while (counter < 5) {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  delay(200);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(200);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(200);
  counter += 1;
}
} else {
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
}
}

int counter = 0;

void setup() {
pinMode(33, OUTPUT);
pinMode(26, INPUT);

Serial.begin(9600);
}

void loop() {
int wertDown = digitalRead(26);
Serial.println(wertDown);

  if (wertDown == 1) 
    {
      counter = 0;
      while (counter < 10) {
        digitalWrite(33,HIGH);
        delay(200);
        digitalWrite(33,LOW);  
        delay(200);
        counter += 1;
      }
      
    }
   else 
   {
    digitalWrite(33,LOW);
   }
}

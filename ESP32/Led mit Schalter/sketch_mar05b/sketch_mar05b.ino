int counter = 0;

void setup() {
pinMode(2, OUTPUT);
pinMode(0, INPUT);

Serial.begin(9600);
}

void loop() {
int wertDown = digitalRead(0);
Serial.println(wertDown);

  if (wertDown == 0) 
    {
      counter = 0;
      while (counter < 10) {
        digitalWrite(2,HIGH);
        delay(200);
        digitalWrite(2,LOW);  
        delay(200);
        counter += 1;
      }
      
    }
   else 
   {
    digitalWrite(2,LOW);
   }
}

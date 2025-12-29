// eingebaute Bibliothek einbinden
# include <Servo.h>
// Bezeichnung des Motors
Servo Motor;
// speichert den analogen Wert des Drehpotentiometers
int ReglerWert;
// Position des Motors
int Position;


void setup()
{
 // Motor an Pin 9 angeschlossen (attach)
 Motor.attach(9);
 Serial.begin(9600);
}
void loop()
{
 int ReglerWert = analogRead(A0);

 Serial.println(ReglerWert);
 /*
 map -> Umwandlung des gelesenen Wertes
 von 0 bis 1023 (analoger Sensorwert)
 auf 0 bis 180 (Drehung des Motors)
 */
 Position = map(ReglerWert, 0, 1023, 0, 180);
 // Motor zur Position bewegen
 Motor.write(Position);
}

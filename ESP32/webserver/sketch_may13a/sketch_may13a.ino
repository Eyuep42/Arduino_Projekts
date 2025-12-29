#include <WiFi.h>
#include <SPIFFS.h>

const char* ssid     = "FRITZ!Box 7490";
const char* password = "80073437732487114646";

WiFiServer server(80);
String header;

const int ledPin = 15;  // LED-Pin
const int tempSensorPin = 26;  // Analoger Temperatur-Sensor

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(tempSensorPin, INPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi verbunden!");
  Serial.println("IP-Adresse: " + WiFi.localIP().toString());

  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS konnte nicht gestartet werden.");
    return;
  }

  server.begin();
}

void loop() {
  WiFiClient client = server.accept();
  if (client) {
    Serial.println("Neuer Client verbunden.");
    String request = client.readStringUntil('\r');
    client.flush();

    // LED Steuerung
    if (request.indexOf("GET /ledOn") >= 0) {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED AN");
    } else if (request.indexOf("GET /ledOff") >= 0) {
      digitalWrite(ledPin, LOW);
      Serial.println("LED AUS");
    }

    // Temperatur abrufen
    if (request.indexOf("GET /temperature") >= 0) {
      float tempC = getTemperature();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-type: text/html");
      client.println("Connection: close");
      client.println(tempC);
      Serial.println("Temperatur gesendet: " + String(tempC) + " °C");
    }

    // Lade HTML-Dateien aus SPIFFS
    if (request.indexOf("GET /index.html") >= 0 || request.indexOf("GET / ") >= 0) {
      sendFile(client, "/index.html");
    } else if (request.indexOf("GET /temp.html") >= 0) {
      sendFile(client, "/temp.html");
    } else if (request.indexOf("GET /led.html") >= 0) {
      sendFile(client, "/led.html");
    } else {
      sendFile(client, "/temp.html");
      //client.println("HTTP/1.1 404 Not Found");
      //client.println("Content-type: text/html");
      //client.println();
      //client.println("<h1>404 - Datei nicht gefunden</h1>");
    }

    client.stop();
    Serial.println("Client getrennt.");
  }
}

// Funktion zur Temperaturberechnung
float getTemperature() {
  int wert = analogRead(tempSensorPin);
  double voltage = (wert / 4096.0) * 3300;  // Umrechnung des ADC-Wertes in Millivolt
  double tempC = (voltage - 500) * 0.1;    // Berechnung der Temperatur in °C

  if (tempC < -40 || tempC > 125) {  // Realistische Temperaturbereiche prüfen
    return -1;  // Fehlerwert
  }

  return tempC;
}

// Funktion zum Senden von Dateien aus SPIFFS
void sendFile(WiFiClient client, const char* filename) {
  File file = SPIFFS.open(filename, "r");
  if (file) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type: text/html");
    client.println("Connection: close");
    client.println();
    
    while (file.available()) {
      client.write(file.read());
    }
    file.close();
  } else {
    client.println("HTTP/1.1 404 Not Found");
    client.println("Content-type: text/html");
    client.println();
    client.println("<h1>404 - Datei nicht gefunden</h1>");
  }
}

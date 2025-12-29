// MeinESP32ClientName, welcher in MQTT zur Identifizuierung genutzt wird, muss geändert werden
#include "WiFi.h"
    // -------------------------
    #include <PubSubClient.h> // bzw. dreieckige Klammern
    const char* MQTT_BROKER = "10.5.4.4";
    WiFiClient espClient;
    PubSubClient client(espClient);
    // -------------------------

    const char *ssid = "FRITZ!Box 7490";
    const char *password = "80073437732487114646"; //siehe FritzBox

    void callback(char* topic, byte* message, unsigned int length) {
       Serial.print("Message arrived on topic: ");
       Serial.print(topic);
       Serial.print(". Message: ");
       String messageTemp;

       for (int i = 0; i < length; i++) {
          Serial.print((char)message[i]);
          messageTemp += (char)message[i];
       }
    Serial.println();
    }

    void reconnect() {
       // Loop until we're reconnected
       while (!client.connected()) {
          Serial.print("Attempting MQTT connection...");
          // Attempt to connect
          if (client.connect("TobiMagZüge")) {
             Serial.println("connected");
             // Subscribe
             client.subscribe("esp32/output");
          } else {
             Serial.print("failed, rc=");
             Serial.print(client.state());
             Serial.println(" try again in 5 seconds");
             delay(5000);
          }
       }
    }

    void setup() {
       Serial.begin(9600);
       Serial.println("");
       Serial.println("------------------------------");
       WiFi.begin(ssid, password);
       while (WiFi.status() != WL_CONNECTED) {
          delay(500);
          Serial.println("Connecting to WiFi..");
       }
       Serial.println("Connected to the WiFi network");
   
       // -------------------------
       client.setServer(MQTT_BROKER, 1883);
       client.connect("TobiMagZüge");
       client.publish("TobiUndEyüp", "Hallo Welt");
       client.subscribe("esp32/output");
       client.setCallback(callback);
       // -------------------------
    }

    void loop() {
       if (!client.connected()) {
          reconnect();
       }
       client.loop();
    }

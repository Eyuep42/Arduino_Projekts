#include <WiFi.h>
#include <PubSubClient.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

const char* ssid = "FRITZ!Box 7490";
const char* password = "80073437732487114646";
const char* mqtt_server = "10.5.4.4";


WiFiClient espClient;
PubSubClient client(espClient);
const int LED_PIN = 2; // GP      IO für die LED

void callback(char* topic, byte* message, unsigned int length) {
String msg = "";
for (int i = 0; i < length; i++) {
msg += (char)message[i];
}

Serial.print("Empfangene Nachricht: ");
lcd.init();                      // initialize the lcd 
lcd.backlight();
lcd.setCursor(3,0);
lcd.print(msg);
Serial.println(msg);

if (msg == "ON") {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED eingeschaltet");
} else if (msg == "OFF") {
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED ausgeschaltet");
}
}

void setup() {
pinMode(LED_PIN, OUTPUT);
Serial.begin(115200);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("\nVerbunden mit WLAN!");

client.setServer(mqtt_server, 1883);
client.setCallback(callback);

while (!client.connected()) {
    Serial.print("Verbinde mit MQTT...");
    if (client.connect("ESP32_LED")) {
        Serial.println("Verbunden!");
        client.subscribe("esp32/led");
    } else {
        Serial.print("Fehlgeschlagen, Fehlercode=");
        Serial.println(client.state());
        delay(5000);
    }
}
}

void loop() {
client.loop();
}

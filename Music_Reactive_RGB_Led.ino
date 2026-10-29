#define BLYNK_TEMPLATE_ID "TMPL3kZZfj5IS"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "REPLACE_WITH_YOUR_BLYNK_TOKEN"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WiFiManager.h>

char auth[] = BLYNK_AUTH_TOKEN;

// ✅ SAFE GPIO PINS ONLY (NO BOOT ISSUES)
const int pins[] = {D1, D2, D5, D6}; 
const int pinCount = 4;

void setup() {
  Serial.begin(115200);

  Serial.println("\nESP8266 Home Automation Starting...");

  // ✅ Initialize all relay pins (ACTIVE LOW → HIGH = OFF)
  for (int i = 0; i < pinCount; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], HIGH); // Relay OFF
  }

  // ✅ WiFi Manager Auto Connect
  WiFiManager wifiManager;

  Serial.println("Connect to WiFi AP: ESP8266-Setup");
  wifiManager.autoConnect("ESP8266-Setup");

  Serial.println("WiFi Connected!");

  // ✅ Start Blynk
  Blynk.begin(auth, WiFi.SSID().c_str(), WiFi.psk().c_str());

  Serial.println("Connected to Blynk Cloud!");
}

// ✅ Blynk Button Controls
BLYNK_WRITE(V0) { controlRelay(0, param.asInt()); } // D1
BLYNK_WRITE(V1) { controlRelay(1, param.asInt()); } // D2
BLYNK_WRITE(V2) { controlRelay(2, param.asInt()); } // D5
BLYNK_WRITE(V3) { controlRelay(3, param.asInt()); } // D6

// ✅ Relay Control Function (ACTIVE LOW)
void controlRelay(int index, int state) {
  digitalWrite(pins[index], state ? LOW : HIGH);

  Serial.print("Relay ");
  Serial.print(index + 1);
  Serial.print(" -> ");
  Serial.println(state ? "ON" : "OFF");
}

void loop() {
  Blynk.run();
}


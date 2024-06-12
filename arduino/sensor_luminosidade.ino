#include <ESP8266WiFi.h>
#include <Wire.h>
#include <BH1750.h>

// Wi-Fi connection to Gateway
const char* ssid = "gateway-ssid";
const char* password = "gateway-password";

// BH1750 sensor init
BH1750 lightMeter;

void setup() {
  Serial.begin(115200);
  
  // Initialize sensors and pins
  Wire.begin(D3, D4);
  lightMeter.begin();
  
  connectToWiFi();
}

void loop() {
  // Read light level from BH1750
  uint16_t lightLevel = lightMeter.readLightLevel();
  
  // Print sensor values to serial
  Serial.print(" %, Light Level: ");
  Serial.print(lightLevel);
  
  // Add delay between readings
  delay(2000);
}

void connectToWiFi() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

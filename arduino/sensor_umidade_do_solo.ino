#include <ESP8266WiFi.h>

// Wi-Fi connection to Gateway
const char* ssid = "gateway-ssid";
const char* password = "gateway-password";

// Pins
#define SOIL_MOISTURE_PIN A0  // Analog pin for soil moisture sensor

void setup() {
  Serial.begin(115200);
  
  connectToWiFi();
}

void loop() {
  // Read soil moisture level from YL-69
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  
  // Print sensor values to serial
  Serial.print(" lx, Soil Moisture: ");
  Serial.println(soilMoistureValue);
  
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

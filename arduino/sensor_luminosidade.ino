#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Wire.h>
#include <BH1750.h>

// Wi-Fi connection to Gateway
const char* ssid = "gateway-ssid";
const char* password = "gateway-password";

// Backend endpoint
const char* serverName = "http://address:port/light";

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
  
  // Prepare data as JSON to sent
  String postData = "{\"light-level\":";
  postData += String(lightLevel);
  postData += "}";

  // Send data to server
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    int httpResponseCode = http.POST(postData);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("Error in WiFi connection");
  }

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

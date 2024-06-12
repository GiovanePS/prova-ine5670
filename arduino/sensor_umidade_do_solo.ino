#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// Wi-Fi connection to Gateway
const char* ssid = "gateway-ssid";
const char* password = "gateway-password";

// Backend endpoint
const char* serverName = "http://address:port/soil";

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
  
  // Prepare data as JSON to sent
  String postData = "{\"soil_moisture\":";
  postData += String(soilMoistureValue);
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

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Wi-Fi connection to Gateway
const char* ssid = "gateway-ssid";
const char* password = "gateway-password";

// Backend endpoint
const char* serverName = "http://address:port/ht";

// Pins
#define DHTPIN D2          // Pin connected to the DHT11
#define DHTTYPE DHT11      // DHT 11

// DHT sensor init
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  
  // Initialize sensors
  dht.begin();
  
  connectToWiFi();
}

void loop() {
  // Read temperature and humidity from DHT11
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  // Print sensor values to serial
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.println(humidity);
  
  // Prepare data as JSON to sent
  String postData = "{\"temperature\":";
  postData += String(temperature);
  postData += ",\"humidity\":";
  postData += String(humidity);
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

  // delay between readings
  delay(2000);
}

// Sample code to Wi-Fi connect
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
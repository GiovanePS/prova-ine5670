#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Wi-Fi connection tos Gateway
const char* ssid = "gateway-ssid";
const char* password = "gateway-password";

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
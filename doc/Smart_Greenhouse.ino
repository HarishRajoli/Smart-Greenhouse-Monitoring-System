#define BLYNK_TEMPLATE_ID "TMPL3qHw9ylmm"
#define BLYNK_TEMPLATE_NAME "smart greenhouse technology"
#define BLYNK_AUTH_TOKEN "hjPT9rf6Lgac1okcUhzd6ApJxgoNATN9"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

// -------------------- Pin Configuration --------------------
#define DHTPIN 4
#define DHTTYPE DHT11
#define SOIL_MOISTURE_PIN 34
#define LDR_PIN 35
#define FAN_PIN 13
#define LED_PIN 14
#define SPRAYER_PIN 27

// -------------------- Threshold Values --------------------
float tempThreshold = 30;        // °C
int lightThreshold = 25;          // 0-1023 scale (depends on LDR)
int soilThreshold = 30;            // percentage (%)

// -------------------- Global Variables --------------------
float temperature, humidity;
int soilMoistureValue, lightIntensity;
bool autoMode = true;

// -------------------- DHT Object --------------------
DHT dht(DHTPIN, DHTTYPE);

// -------------------- Blynk Auth & WiFi --------------------
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "HARISH";
char pass[] = "Harish@123";

// -------------------- Blynk Virtual Pins --------------------
// V0 = Temperature Display
// V1 = Humidity Display
// V2 = Soil Moisture Display
// V3 = Light Intensity Display
// V4 = Fan Button (Manual)
// V5 = LED Light Button (Manual)
// V6 = Sprayer Button (Manual)
// V7 = Auto/Manual Mode Switch

// -------------------- Setup --------------------
void setup() {
  Serial.begin(115200);
  dht.begin();
  Blynk.begin(auth, ssid, pass);

  pinMode(FAN_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SPRAYER_PIN, OUTPUT);

  digitalWrite(FAN_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(SPRAYER_PIN, LOW);

  Serial.println("Smart Greenhouse System Initialized");
}

// -------------------- Read Sensors --------------------
void readSensors() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  soilMoistureValue = map(soilMoistureValue, 4095, 0, 0, 100); // Convert to % (depends on sensor)

  lightIntensity = analogRead(LDR_PIN);
  lightIntensity = map(lightIntensity, 0, 4095, 0, 1023);

  Serial.print("Temp: "); Serial.print(temperature);
  Serial.print("°C | Humidity: "); Serial.print(humidity);
  Serial.print("% | Soil: "); Serial.print(soilMoistureValue);
  Serial.print("% | Light: "); Serial.println(lightIntensity);
}

// -------------------- Send Data to Blynk --------------------
void sendToBlynk() {
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V2, soilMoistureValue);
  Blynk.virtualWrite(V3, lightIntensity);
}

// -------------------- Automatic Control --------------------
void autoControl() {
  if (autoMode) {
    // Fan Control
    if (temperature > tempThreshold) {
      digitalWrite(FAN_PIN, LOW);
      Blynk.virtualWrite(V4, 0);
    } else {
      digitalWrite(FAN_PIN, HIGH);
      Blynk.virtualWrite(V4, 1);
    }

    // Light Control
    if (lightIntensity < lightThreshold) {
      digitalWrite(LED_PIN, LOW);
      Blynk.virtualWrite(V5, 0);
    } else {
      digitalWrite(LED_PIN, HIGH);
      Blynk.virtualWrite(V5, 1);
    }

    // Sprayer Control
    if (soilMoistureValue < soilThreshold) {
      digitalWrite(SPRAYER_PIN, LOW);
      Blynk.virtualWrite(V6, 0);
    } else {
      digitalWrite(SPRAYER_PIN, HIGH);
      Blynk.virtualWrite(V6, 1);
    }
  }
}

// -------------------- Manual Control (Blynk Buttons) --------------------
BLYNK_WRITE(V4) {
  if (!autoMode) digitalWrite(FAN_PIN, param.asInt());
}

BLYNK_WRITE(V5) {
  if (!autoMode) digitalWrite(LED_PIN, param.asInt());
}

BLYNK_WRITE(V6) {
  if (!autoMode) digitalWrite(SPRAYER_PIN, param.asInt());
}

// -------------------- Auto/Manual Mode Switch --------------------
BLYNK_WRITE(V7) {
  autoMode = param.asInt();
  Serial.println(autoMode ? "Auto Mode Enabled" : "Manual Mode Enabled");
}

// -------------------- Loop --------------------
void loop() {
  Blynk.run();
  readSensors();
  sendToBlynk();
  autoControl();
  delay(2000); // Update every 2 seconds
}
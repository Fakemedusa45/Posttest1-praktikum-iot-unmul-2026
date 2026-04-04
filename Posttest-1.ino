#define BLYNK_TEMPLATE_ID "TMPL6E4kjVvtt"
#define BLYNK_TEMPLATE_NAME "Posttest 1"
#define BLYNK_AUTH_TOKEN "vLSU4YSsI1Jx3DQSsqhvtLc5z0bgpl9Q"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Pin (FIX: pakai pin ADC yang valid di ESP32-S3)
const int mqPin = 4;
const int led1 = 15;
const int led2 = 16;
const int led3 = 17;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "sapi";
char pass[] = "#12345678";

int gasValue = 0;
bool manualMode = false;

BlynkTimer timer;

// Kontrol dari Blynk (hanya saat aman)
BLYNK_WRITE(V1) { if(manualMode) digitalWrite(led1, param.asInt()); }
BLYNK_WRITE(V2) { if(manualMode) digitalWrite(led2, param.asInt()); }
BLYNK_WRITE(V3) { if(manualMode) digitalWrite(led3, param.asInt()); }

// Fungsi kedip (versi lama kamu)
void blinkLEDNonBlocking(int pin, int durationSeconds) {
  unsigned long startMillis = millis();
  while (millis() - startMillis < (durationSeconds * 1000)) {
    digitalWrite(pin, HIGH);
    delay(200);
    digitalWrite(pin, LOW);
    delay(200);
    Blynk.run(); // biar tidak disconnect
  }
}

void checkSensor() {
  gasValue = analogRead(mqPin);
  Blynk.virtualWrite(V0, gasValue);

  Serial.println(gasValue);

  // Matikan semua LED dulu (biar tidak tumpuk)
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  // LOGIKA SESUAI SOAL
  if (gasValue >= 0 && gasValue <= 700) {
    manualMode = false;
    blinkLEDNonBlocking(led1, 3); // LED1 → 3 detik
  } 
  else if (gasValue >= 701 && gasValue <= 900) {
    manualMode = false;
    blinkLEDNonBlocking(led2, 5); // LED2 → 5 detik
  } 
  else if (gasValue > 900) {
    manualMode = false;
    blinkLEDNonBlocking(led3, 7); // LED3 → 7 detik
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Warmup sensor
  Serial.println("Warming up MQ135...");
  delay(1000);

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, checkSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
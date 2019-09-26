#include <Wire.h>

#define PUMP_DELAY 120000
#define ENV_READING_DELAY 2000

#define TOO_DRY 860
#define WELL_OK 500
#define TOO_WET 400

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  setupSerial();
  setupEEPROM();
  setupNetwork();
  setupServer();

  // Won't call Wire.begin() because bme280 lib already calls it at init
  // Wire.begin();
  setupBME280();
  setupGY30();
  setupMultiplexer();
  setupRelay();
  setupInflux();

}

struct EnvData {

  int soil = 0, light = 0;
  float temp = 0, rh = 0, pa = 0;
  float lux = 0;

  unsigned long lastReading = 0;
  unsigned long lastPumpActivation = 0;

} env;

unsigned long now = 0;

void loop() {

  now = millis();
  if (now - env.lastReading > ENV_READING_DELAY) {

    readMux();
    readBme();
    readGy30();
    env.lastReading = now;

    logData();
    blink();

    if (env.soil > TOO_DRY && now - env.lastPumpActivation > PUMP_DELAY) {
      openPump();
    }

  }

  handleRequest();

}

void blink() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(10);
  digitalWrite(LED_BUILTIN, HIGH);
}

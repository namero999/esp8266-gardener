#define RELAY_SEL D0
#define PUMP_ON_TIME 2000

void setupRelay() {
  pinMode(RELAY_SEL, OUTPUT);
  digitalWrite(RELAY_SEL, LOW);
}

void openPump() {
  logEvent();
  digitalWrite(RELAY_SEL, HIGH);
  delay(PUMP_ON_TIME);
  digitalWrite(RELAY_SEL, LOW);
  env.lastPumpActivation = now;
}

#include "BH1750.h"

BH1750 lightMeter;

void setupGY30() {
  Serial.println(
    lightMeter.begin(BH1750::ONE_TIME_HIGH_RES_MODE)
    ? "GY30 found and configured"
    : "Problems configuring GY30");
}


void readGy30() {
  env.lux = lightMeter.readLightLevel();
}

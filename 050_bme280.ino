#include "BME280.h"

BME280 bme(Wire, 0x76);

void setupBME280() {
  int result = bme.begin();
  result += bme.setTemperatureOversampling(BME280::SAMPLING_X1);
  result += bme.setPressureOversampling(BME280::SAMPLING_X1);
  result += bme.setHumidityOversampling(BME280::SAMPLING_X1);
  result += bme.setIirCoefficient(BME280::IIRC_OFF);
  result += bme.setStandbyTime(BME280::STANDBY_1000_MS);
  // result += bme.setForcedMode();
  // Serial.println(result);
  Serial.println(result == 6 ? "BME280 found and configured" : "Problems configuring BME280");
}

void readBme() {
  bme.readSensor();
  env.temp = bme.getTemperature_C();
  env.rh = bme.getHumidity_RH();
  env.pa = bme.getPressure_Pa();
}

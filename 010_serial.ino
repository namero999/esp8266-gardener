void setupSerial() {
  Serial.begin(74880);
  while (!Serial) {}
}

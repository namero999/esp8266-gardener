#include <ESP_EEPROM.h>

struct Network {
  char networkName[32];
  char networkPass[32];
  byte collector_ip[4];
  int collector_tcp_port;
  int collector_udp_port;
} network;

void setupEEPROM() {

  EEPROM.begin(sizeof(Network));

  EEPROM.get(0, network);

  Serial.print("EEPROM data read, networkName=");
  Serial.println(network.networkName);

}

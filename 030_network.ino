#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiUdp.h>

#define NONE 0
#define TCP 1
#define UDP 2

const int TX_MODE = NONE;

HTTPClient http;
WiFiUDP udp;

IPAddress collector_ip(network.collector_ip[0],
                       network.collector_ip[1],
                       network.collector_ip[2],
                       network.collector_ip[3]);

void setupNetwork() {

  WiFi.mode(WIFI_STA);
  WiFi.begin(network.networkName, network.networkPass);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }

  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

}

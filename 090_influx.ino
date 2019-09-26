char dbName[16] = "garden";
char address[64];
char logLine[128];

void setupInflux() {
  sprintf(address, "http://%s:%d/write?db=%s", collector_ip.toString().c_str(), network.collector_tcp_port, dbName);
  Serial.println(address);
}

void logData() {
  sprintf(logLine, "garden,device=D1 soil=%d,light=%d,lux=%.2f,temp=%.2f,rh=%.2f,pa=%.2f", env.soil, env.light, env.lux, env.temp, env.rh, env.pa);
  Serial.println(logLine);
  logToInflux();
}

void logEvent() {
  sprintf(logLine, "garden,device=D1 pump=\"%s\"", "Pump on");
  Serial.println(logLine);
  logToInflux();
}

void logToInflux() {

  if (TX_MODE == TCP) {
    http.begin(address);
    http.addHeader("Content-Type", "text/plain");
    http.POST(logLine);
    http.end();
  } else if (TX_MODE == UDP) {
    udp.beginPacket(collector_ip, network.collector_udp_port);
    udp.print(logLine);
    udp.endPacket();
  }

}

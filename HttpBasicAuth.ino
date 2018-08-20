#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <ESP8266WebServer.h>
#include "API.h"
#include "conf.h"

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, SECRET);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Connect Failed! Rebooting...");
    delay(1000);
    ESP.restart();
  }
  ArduinoOTA.begin();

  server.on("/", []() {
    if (!server.authenticate(USER, PASS)) {
      return server.requestAuthentication();
    }
    //server.send(200, "text/plain", "Login OK");
    hello(&server);
  });
  server.begin();

  Serial.print("Open http://");
  Serial.print(WiFi.localIP());
  Serial.println("/ in your browser to see it working");
}

void loop() {
  ArduinoOTA.handle();
  server.handleClient();
}

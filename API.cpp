#include <ESP8266WebServer.h>
#include "API.h"
#include "conf.h"

extern ESP8266WebServer server;

void root(){
	if (!server.authenticate(USER, PASS)) {
    server.requestAuthentication();
	}
	Serial.println("now printing hello root function");
	server.send(200, "text/plain", "I am Root!!");
}

void test(){
  if (!server.authenticate(USER, PASS)) {
    server.requestAuthentication();
  }
  Serial.println("now printing test function");
  server.send(200, "text/plain", "Testing API!!");
}

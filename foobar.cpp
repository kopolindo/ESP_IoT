#include <ESP8266WebServer.h>
#include "foobar.h"

void hello(ESP8266WebServer *server){
  Serial.println("now printing hello function");
	server->send(200, "text/plain", "e KABOOOOOOM!!");
}

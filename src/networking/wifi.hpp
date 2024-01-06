#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiManager.h>


class wifi {
  WiFiManager wm;

 public:
  void init();
  String requestGet(String adress);
};

#include "wifi.hpp"

void wifi::init() { wm.autoConnect("AutoConnectAP"); }

String wifi::requestGet(String adress) {
  WiFiClient client;
  HTTPClient http;

  http.begin(client, adress);

  int httpResponseCode = http.GET();

  String payload = "{}"; 

  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    // payload = http.getString();
    DynamicJsonDocument doc(49152);

    DeserializationError error = deserializeJson(doc, http.getString(), DeserializationOption::NestingLimit(12));

    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
    }
    JsonObject Children_0 = doc["Children"][0];
    Serial.println(String(Children_0["Text"]));
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
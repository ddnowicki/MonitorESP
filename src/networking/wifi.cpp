#include "wifi.hpp"

void wifi::init() { wm.autoConnect("AutoConnectAP"); }

String wifi::requestGet(String adress) {
  if ((WiFi.status() == WL_CONNECTED)) {
    std::unique_ptr<BearSSL::WiFiClientSecure> client(
        new BearSSL::WiFiClientSecure);

    client->setInsecure();

    HTTPClient https;

    Serial.print("[HTTPS] begin...\n");
    if (https.begin(*client, adress)) {
      Serial.print("[HTTPS] GET...\n");
      int httpCode = https.GET();
      if (httpCode > 0) {
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);
        if (httpCode == HTTP_CODE_OK ||
            httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          return https.getString();
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n",
                      https.errorToString(httpCode).c_str());
      }

      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
  }

  return "{\"Sucess\":false}";
}
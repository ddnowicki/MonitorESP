#include "wifi.hpp"

wifi::wifi(String ssid, String password) {
  WiFi.begin(ssid, password);
}

#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>

class json {
 public:
  std::pair<String, String> decompileSpec(String data);
};

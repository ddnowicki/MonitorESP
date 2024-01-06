#include "json.hpp"

std::pair<String, String> json::decompileSpec(String data) {
    JsonDocument doc;

    deserializeJson(doc, data);
    
    return std::pair<String, String>(doc["Lines"][0]["Data"], doc["Lines"][1]["Data"]);
}
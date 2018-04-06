#include "LogLevel.h"

namespace Common {

    LogLevel::LogLevel() {}

    void from_json(const nlohmann::json &j, LogLevel &level) {

        level.key = j.at("key").get<std::string>();
        level.ext = j.at("ext").get<std::string>();
        level.name = j.at("name").get<std::string>();

    }

    void to_json(nlohmann::json &j, const LogLevel &level) {

        j = nlohmann::json{{"key",  level.key},
                           {"name", level.name},
                           {"ext",  level.ext}};
    }


}
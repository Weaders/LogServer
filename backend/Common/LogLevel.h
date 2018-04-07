#pragma once

#include <string>
#include "./../json/json.hpp"

namespace Common {

    class LogLevel {

    public:
        LogLevel();

        std::string name;
        std::string ext;
        std::string key;

    };

    void to_json(nlohmann::json &j, const LogLevel &level);
    void from_json(const nlohmann::json &j, LogLevel &level);


}
#pragma once

#include "../Common/Config.h"
#include "./../json/json.hpp"
#include "boost/algorithm/string.hpp"
#include "boost/filesystem.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace Services {

namespace fs = boost::filesystem;

class LogFile {

public:
    LogFile(const std::string&);

    std::vector<nlohmann::json> getMsgs();

    std::string path;

    std::shared_ptr<Common::LogLevel> level = nullptr;
    std::string time;
    std::string fileName;

    bool isValidLogFile = false;

protected:
    void processPath();
};

void to_json(nlohmann::json& j, const LogFile&);
void from_json(const nlohmann::json& j, LogFile&);

} // namespace Services
#pragma once

#include <string>
#include "../Common/Config.h"
#include "boost/filesystem.hpp"
#include "boost/algorithm/string.hpp"
#include <iostream>
#include <vector>
#include "./../json/json.hpp"

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

}
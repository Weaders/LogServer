#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <regex>


#include "../ThirdParty/json.hpp"
#include "LogLevel.h"
#include "StrTemplate.h"

namespace Common {

    class Config {

    public:
        static std::shared_ptr<Config> getInstance();

        unsigned port = 8080;

        std::string logFileTemplate = "";
        std::string logsFolder = "";
        std::string logExtension = "";
        std::vector<std::shared_ptr<LogLevel>> logLevels;

        std::shared_ptr<Common::StrTemplate> logFileTemplateObj;

        std::string path;

    protected:

        std::vector<LogLevel> _logLevels;

        static std::shared_ptr<Config> c;

        explicit Config(const std::string& p);

        void load();

    };

}
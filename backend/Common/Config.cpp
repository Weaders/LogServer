#include "Config.h"

namespace Common {

    std::shared_ptr<Config> Config::getInstance() {

        if (Config::c == nullptr) {
            Config::c = std::shared_ptr<Config>(new Config("./config.json"));
        }

        return Config::c;

    }

    Config::Config(const std::string &p) : path(p) {
        this->load();
    }

    void Config::load() {

        std::ifstream ifs(this->path);

        auto jsonContent = std::string(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());
        auto parseJson = nlohmann::json::parse(jsonContent);

        this->logsFolder = parseJson.at("logsFolder").get<std::string>();
        this->logExtension = parseJson.at("logExtension").get<std::string>();
        this->logFileTemplate = parseJson.at("logFileTemplate").get<std::string>();
        this->port = parseJson.at("port").get<unsigned>();

        for (auto &logLevel: parseJson[ "logLevels" ]) {
            this->_logLevels.push_back(logLevel);
        }

        for (unsigned i = 0; i < this->_logLevels.size(); i++) {
            this->logLevels.push_back(std::shared_ptr<LogLevel>(&this->_logLevels[i]));
        }

        this->logFileTemplateObj = std::make_shared<StrTemplate>(this->logFileTemplate);

        if (this->logsFolder.back() != '/') {
            this->logsFolder += '/';
        }

    }

    std::shared_ptr<Config> Config::c = nullptr;

}
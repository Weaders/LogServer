#include "LogFile.h"

namespace Services {

LogFile::LogFile(const std::string& path)
    : path(path) {
    this->processPath();
}

void LogFile::processPath() {

    this->isValidLogFile = false;

    auto config = Common::Config::getInstance();
    std::smatch match;
    auto path = fs::path(this->path);

    if (!fs::is_regular_file(path)) {
        return;
    }

    this->fileName = path.filename().string();

    if (std::regex_match(this->fileName, match, config->logFileTemplateObj->regular)) {

        this->isValidLogFile = true;

        for (int i = 1; i < match.size(); i++) {

            auto paramName = config->logFileTemplateObj->params[i - 1];

            if (paramName == "time") {
                this->time = match[i].str();
            } else if (paramName == "level") {

                for (auto& logLevel : config->logLevels) {

                    if (logLevel->key == match[i].str()) {

                        this->level = logLevel;
                        break;
                    }
                }
            }
        }
    }

    if (this->level == nullptr) { // If not found level
        this->isValidLogFile = false;
    }
}

std::vector<nlohmann::json> LogFile::getMsgs() {

    std::vector<nlohmann::json> msgs;

    if (!this->isValidLogFile) {
        return msgs;
    }

    auto ifs = std::ifstream(this->path);
    auto content = std::string(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());

    std::vector<std::string> stringMessages;

    boost::algorithm::split(stringMessages, content, boost::algorithm::is_any_of("\r\n"));

    for (auto& msg : stringMessages) {

        if (!msg.empty()) {
            msgs.push_back(nlohmann::json::parse(msg));
        }
    }

    return msgs;
}

void to_json(nlohmann::json& j, const LogFile& logFile) {

    j = { { "time", logFile.time },
        { "fileName", logFile.fileName },
        { "level", *logFile.level } };
}

void from_json(const nlohmann::json& j, LogFile& logFile) {

    logFile.time = j.at("time").get<std::string>();
    logFile.fileName = j.at("fileName").get<std::string>();

    auto jsonLevel = j.at("level").get<Common::LogLevel>();

    auto c = Common::Config::getInstance();

    for (auto& logLevel : c->logLevels) {

        if (jsonLevel.key == logLevel->key) {

            logFile.level = logLevel;
            break;
        }
    }
}

} // namespace Services

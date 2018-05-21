#pragma once

#include "LogFile.h"
#include "boost/filesystem.hpp"
#include <string>
#include <vector>

namespace fs = boost::filesystem;

namespace Services {

class LogsReader {

public:
    LogsReader(const std::string& path, const std::string& ext);

    std::vector<LogFile> getLogsFiles();

protected:
    std::string path;
    std::string ext;
};

} // namespace Services
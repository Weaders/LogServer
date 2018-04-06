#pragma once

#include <string>
#include <vector>
#include "boost/filesystem.hpp"
#include "LogFile.h"

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

}
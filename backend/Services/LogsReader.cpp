#include "LogsReader.h"
#include <iostream>

namespace Services {

LogsReader::LogsReader(const std::string& path, const std::string& ext)
    : path(path)
    , ext(ext) {}

std::vector<LogFile> LogsReader::getLogsFiles() {

    std::vector<LogFile> files;

    for (boost::filesystem::directory_entry& file : boost::filesystem::directory_iterator(this->path)) {

        if (!fs::is_regular_file(file)) {
            continue;
        }

        auto fileName = file.path().native();

        auto extension = file.path().extension().string();

        if (extension == this->ext) {

            auto f = LogFile(fileName);

            if (f.isValidLogFile) {
                files.emplace_back(f);
            }
        }
    }

    return files;
}

} // namespace Services
#pragma once

#include <string>
#include <vector>
#include <regex>

namespace Common {

    class StrTemplate {
    public:
        StrTemplate(const std::string& strTemplate);

        std::string source;
        std::regex regular;
        std::vector<std::string> params;

    protected:
        void parse();
    };

}
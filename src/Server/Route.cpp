#include "Route.h"
#include "../Common/StrTemplate.h"
#include <iostream>

namespace Server {

    Route::Route(const std::string &str, std::shared_ptr<Action> action) {

        this->_sourceStr = str;
        this->action = std::move(action);
        this->_setRegex();
    }

    void Route::_setRegex() {

        std::string s = this->_sourceStr;

        auto strTemplate = Common::StrTemplate(this->_sourceStr);

        this->_regex = strTemplate.regular;
        this->_params = strTemplate.params;

    }

    RouteParams Route::exec(const std::string &path) {

        std::smatch match;
        RouteParams params;

        if (std::regex_match(path, match, this->_regex)) {

            for (int i = 1; i < match.size(); i++) {
                params.insert(std::make_pair(this->_params[ i - 1 ], match[ i ].str()));
            }

        }

        return params;

    }

    bool Route::check(const std::string &path) {
        return std::regex_match(path, this->_regex);
    }

} // namespace Server
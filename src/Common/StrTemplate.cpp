#include "StrTemplate.h"

namespace Common {

    StrTemplate::StrTemplate(const std::string &strTemplate) : source(strTemplate){
        this->parse();
    }

    void StrTemplate::parse() {

        std::regex e(":[^/.\\\\]+");
        std::smatch m;
        std::string s = this->source;

        std::string regexNew;
        std::vector<std::string> variables;

        while (std::regex_search(s, m, e)) {

            regexNew += m.prefix().str();

            for (auto c : m) {

                regexNew += ("([^/\\s]+)");
                this->params.push_back(c.str().substr(1));
            }

            s = m.suffix().str();

        }

        if (regexNew.empty()) {
            regexNew = this->source;
        } else {
            regexNew += s;
        }

        this->regular = std::regex(regexNew);

    }

}

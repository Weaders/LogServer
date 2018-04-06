#pragma once

#include <string>
#include <map>
#include <memory>

namespace Server {

    class Response {

    public:

        const std::string CONTENT_TYPE_HEADER = "Content-Type";
        const short DEFAULT_HTTP_CODE = 200;

        std::map<std::string, std::string> headers;

        Response();

        Response* responseCode(const short &code);
        short responseCode();

        Response* type(const std::string &type);
        std::string type();

        Response* header(const std::string &header, const std::string &val);
        std::string header(const std::string &header);

        Response* body(const std::string&);
        std::string body();

        Response* jsonResponse(const std::string&);

    protected:
        short _responseCode = Response::DEFAULT_HTTP_CODE;
        std::string _body;

    };


}
#include "Response.h"

namespace Server {

    Response::Response() {

        this->responseCode(Response::DEFAULT_HTTP_CODE);
        this->type("text/html");

    }

    Response* Response::responseCode(const short &code) {

        this->_responseCode = code;
        return this;

    }

    short Response::responseCode() {
        return this->_responseCode;
    }

    Response* Response::type(const std::string &type) {

        this->headers[Response::CONTENT_TYPE_HEADER] = type + "; charset=utf-8";
        return this;

    }

    std::string Response::type() {
        return this->headers[Response::CONTENT_TYPE_HEADER];
    }

    std::string Response::header(const std::string &header) {
        return this->headers[header];
    }

    Response* Response::header(const std::string &header, const std::string &val) {

        this->headers[header] = val;
        return this;

    }

    Response* Response::body(const std::string &body) {

        this->_body = body;
        return this;

    }

    Response* Response::jsonResponse(const std::string &json) {

        this->responseCode(200)
            ->type("application/Json")
            ->body(json);

        return this;

    }

    std::string Response::body() {
        return this->_body;
    }

}
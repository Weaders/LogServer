#include "Server.h"
#include "Request.h"
#include "Route.h"
#include <cstring>
#include <iostream>
#include <typeinfo>
#include <sys/stat.h>
#include <fstream>

namespace Server {

    Server::Server() {}

    void Server::start(uint16_t port) {

        auto base = event_base_new();

        if (base == nullptr) {

            fprintf(stderr, "Couldn't create an event_base: exiting\n");
            return;
        }

        auto http = evhttp_new(base);

        if (http == nullptr) {

            fprintf(stderr, "Couldn't create an event_http\n");
            return;
        }

        auto socket = evhttp_bind_socket_with_handle(http, "0.0.0.0", port);

        if (socket == nullptr) {

            fprintf(stderr, "Couldn't bind socket");
            return;
        }

        std::cout << "Server start at " + std::to_string(port) << std::endl;

        evhttp_set_gencb(http,
                         [](evhttp_request *req, void *arg) -> void {

                             auto server = static_cast<Server *>(arg);
                             auto uri = evhttp_request_get_evhttp_uri(req);
                             auto uriPath = evhttp_uri_get_path(uri);
                             std::shared_ptr<Response> response = nullptr;

                             if (std::string(uriPath) == "/") {
                                 response = server->getHomePage();
                             }

                             auto httpMethod = Server::convertEvCmd(evhttp_request_get_command(req));

                             if (response == nullptr) {

                                 for (auto r : server->routes) {

                                     if (r.check(uriPath, httpMethod)) {

                                         auto params = r.exec(evhttp_uri_get_path(uri));
                                         auto request = Request(req, params);
                                         response = r.action->run(request);

                                         break;

                                     }
                                 }

                             }

                             if (response == nullptr) {

                                 std::string fileName;

                                 if (server->staticRouteFileName(uriPath, fileName)) {
                                     response = server->getFileResponse(fileName);
                                 } else {

                                     if (server->isReturnHomeOn404()) {
                                         response = server->getHomePage();
                                     } else {
                                         response = server->get404Response();
                                     }

                                 }

                             }

                             server->sendResponse(req, response);

                         },
                         this);

        event_base_dispatch(base);
    }

    void Server::route(const std::string &path, std::shared_ptr<Action> action, const HTTP_METHOD& method) {

        Route r(path, std::move(action), method);
        this->routes.push_back(r);

    }

    void Server::staticRoute(const std::string &path, const std::string &folder) {

        this->staticRoutes.insert(std::make_pair(path, folder));
    }

    void Server::websocketRoute(const std::string &msg, WebSocketAction *action) {

    }

    void Server::addExtensionType(const std::string &extension, const std::string &contentType) {
        this->extensions.insert(std::make_pair(extension, contentType));
    }

    bool Server::staticRouteFileName(const std::string &virtualPath, std::string &filePath) {

        for (const auto &staticRoute : this->staticRoutes) {

            std::smatch m;
            std::regex e("^" + staticRoute.first + "(.+)$");

            auto result = std::regex_search(virtualPath, m, e);

            if (result) {

                struct stat buffer;

                if (stat((staticRoute.second + m.str(1)).c_str(), &buffer) == 0) {

                    filePath = staticRoute.second + m.str(1);
                    return true;

                }

            }

        }

        return false;

    }

    std::shared_ptr<Response> Server::getFileResponse(const std::string &file) {

        auto response = std::make_shared<Response>();

        std::ifstream ifs(file);
        auto content = std::string(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());

        response->body(content)
                ->responseCode(200);

        auto dotKey = file.find_last_of('.');

        if (dotKey != -1 && dotKey != file.length() - 1) {

            auto extIt = this->extensions.find(file.substr(dotKey + 1));

            if (extIt != this->extensions.end()) {
                response->type(extIt->second);
            }

        }

        return response;

    }

    std::shared_ptr<Response> Server::get404Response() {

        auto response = std::make_shared<Response>();

        response->body("404 mother fucker")
                ->responseCode(404);

        return response;

    }

    void Server::sendResponse(evhttp_request *req, std::shared_ptr<Response> response) {

        auto buffer = evbuffer_new();
        auto b = response->body();
        auto reqHeaders = evhttp_request_get_output_headers(req);

        for (const auto &pair : response->headers) {
            evhttp_add_header(reqHeaders, pair.first.c_str(), pair.second.c_str());
        }

        evbuffer_add(buffer, b.c_str(), b.size());

        evhttp_send_reply(req, response->responseCode(), nullptr, buffer);

        evbuffer_free(buffer);

    }

    void Server::fileHomePage(const std::string &filePath, bool returnOn404) {

        this->fileHomePagePath = filePath;
        this->returnHomeOn404 = returnOn404;

    }

    std::shared_ptr<Response> Server::getHomePage() {

        if (!this->fileHomePagePath.empty()) {
            return this->getFileResponse(this->fileHomePagePath);
        } else {
            return nullptr;
        }

    }

    HTTP_METHOD Server::convertEvCmd(const evhttp_cmd_type &cmd) {

        switch (cmd) {
            case EVHTTP_REQ_GET:
                return HTTP_METHOD::GET;
            case EVHTTP_REQ_POST:
                return HTTP_METHOD::POST;
            case EVHTTP_REQ_DELETE:
                return HTTP_METHOD::DELETE;
            case EVHTTP_REQ_PUT:
                return HTTP_METHOD::PUT;
            case EVHTTP_REQ_OPTIONS:
                return HTTP_METHOD::OPTIONS;
            case EVHTTP_REQ_HEAD:
                return HTTP_METHOD::HEAD;
            case EVHTTP_REQ_CONNECT:
                return HTTP_METHOD::CONNECT;
            case EVHTTP_REQ_PATCH:
                return HTTP_METHOD::PATCH;
            case EVHTTP_REQ_TRACE:
                return HTTP_METHOD::TRACE;
        }

        return HTTP_METHOD::GET;

    }

    bool Server::isReturnHomeOn404() {
        return this->returnHomeOn404;
    }

} // namespace Server
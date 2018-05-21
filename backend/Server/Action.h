#pragma once

#include "Request.h"
#include "Response.h"
#include <memory>

namespace Server {

class Action {

public:
    Action();
    ~Action();

    virtual std::shared_ptr<Response> run(const Request&) = 0;
};

} // namespace Server

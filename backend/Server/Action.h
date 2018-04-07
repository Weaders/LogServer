#pragma once

#include <memory>
#include "Response.h"
#include "Request.h"

namespace Server {

    class Action {

    public:

        Action();
        ~Action();

        virtual std::shared_ptr<Response> run(const Request&) = 0;

    };

}

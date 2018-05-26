#include "SocketAction.h"
#include <functional>
#include <memory>
#include <type_traits>
#include <typeinfo>

namespace Server {
namespace WebSocket {

    class SocketActionGenerator {
    public:
        void setGenerateCb(std::function<std::shared_ptr<SocketAction>(const std::string&, std::shared_ptr<SocketConnection>)> f) {
            this->genCb = f;
        }

        std::shared_ptr<SocketAction> getAction(const std::string& path, std::shared_ptr<SocketConnection> _conn) {
            return this->genCb(path, _conn);
        }

    protected:
        std::function<std::shared_ptr<SocketAction>(const std::string&, std::shared_ptr<SocketConnection>)> genCb;
    };

} // namespace WebSocket

} // namespace Server
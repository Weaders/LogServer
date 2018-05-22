#include "FrameReader.h"
#include "SocketAction.h"
#include <event2/http.h>
#include <memory>

namespace Server {

namespace WebSocket {

    class SocketConnection {
    public:
        enum CONNECTION_STATE {
            CLOSED,
            CLOSING,
            OPENED
        };

        ~SocketConnection();
        SocketConnection(evhttp_connection*, std::shared_ptr<SocketAction>);

        CONNECTION_STATE state = CONNECTION_STATE::OPENED;

        evhttp_connection* getConnection();
        std::shared_ptr<FrameReader> getFrameReader();

        std::shared_ptr<SocketAction> getAction();

        void close();

    protected:
        evhttp_connection* _conn = nullptr;
        std::shared_ptr<FrameReader> _reader = nullptr;
        std::shared_ptr<SocketAction> _action = nullptr;
    };

} // namespace WebSocket

} // namespace Server
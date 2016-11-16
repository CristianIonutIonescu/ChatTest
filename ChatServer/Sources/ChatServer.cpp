/**
 * @file ChatServer.cpp
 *
 * @author c.ionescu@iquestgroup.com
 * @copyright (c) 2016 iQuest Group
 */

#include "ChatServer.h"
#include "ChatSession.h"

#include <memory>

namespace server {

using boost::asio::ip::tcp;

ChatServer::ChatServer(boost::asio::io_service& io_service,
        const tcp::endpoint& endpoint) :
        acceptor_(io_service, endpoint), socket_(io_service) {
    Accept();
}

void ChatServer::Accept() {
    acceptor_.async_accept(socket_, [this](boost::system::error_code ec)
    {
        if (!ec)
        {
            std::make_shared<ChatSession>(std::move(socket_), room_)->Start();
        }

        Accept();
    });
}
}

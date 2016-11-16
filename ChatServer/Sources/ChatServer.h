/**
 * @file ChatServer.h
 *
 * @author c.ionescu@iquestgroup.com
 * @copyright (c) 2016 iQuest Group
 */

#ifndef CHATSERVER_H_
#define CHATSERVER_H_

#include "ChatRoom.h"

#include <boost/asio.hpp>


namespace server {

using boost::asio::ip::tcp;

class ChatServer {
public:
    ChatServer(boost::asio::io_service& io_service,
            const tcp::endpoint& endpoint);

private:
    void Accept();

    tcp::acceptor acceptor_;
    tcp::socket socket_;
    ChatRoom room_;
};
}
#endif /* CHATSERVER_H_ */

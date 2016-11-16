/**
 * @file ChatClient.h
 *
 * @author c.ionescu@iquestgroup.com
 * @copyright (c) 2016 iQuest Group
 */

#ifndef CHATCLIENT_H_
#define CHATCLIENT_H_

#include "../../ChatServer/Sources/ChatMessage.h"

#include <boost/asio.hpp>
#include <deque>

using boost::asio::ip::tcp;


typedef std::deque<ChatMessage> chat_message_queue;

class ChatClient {
public:
    ChatClient(boost::asio::io_service& io_service,
            tcp::resolver::iterator endpoint_iterator, std::string user_name);

    void Write(const ChatMessage& msg);

    void Close();

private:
    void Connect(tcp::resolver::iterator endpoint_iterator);

    void ReadHeader();

    void ReadBody();

    void Write();

    boost::asio::io_service& io_service_;
    tcp::socket socket_;
    ChatMessage read_msg_;
    chat_message_queue write_msgs_;
    std::string user_name_;
};

#endif /* CHATCLIENT_H_ */

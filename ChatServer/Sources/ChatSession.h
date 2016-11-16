/**
 * @file ChatSession.h
 *
 * @author c.ionescu@iquestgroup.com
 * @copyright (c) 2016 iQuest Group
 */

#ifndef CHATSESSION_H_
#define CHATSESSION_H_

#include "ChatRoom.h"

#include <boost/asio.hpp>

#include <memory>

namespace server {
using boost::asio::ip::tcp;

class ChatSession: public ChatParticipant, public std::enable_shared_from_this<
        ChatSession> {
public:
    ChatSession(tcp::socket socket, ChatRoom& room);

    void Start();

    void Deliver(const ChatMessage& msg);

private:
    void ReadHeader();

    void ReadBody();

    void Write();

    tcp::socket socket_;
    ChatRoom& room_;
    ChatMessage read_msg_;
    chat_message_queue write_msgs_;
};
}

#endif /* CHATSESSION_H_ */

/**
 * @file ChatSession.cpp
 *
 * @author c.ionescu@iquestgroup.com
 * @copyright (c) 2016 iQuest Group
 */

#include "ChatSession.h"

namespace server {

ChatSession::ChatSession(tcp::socket socket, ChatRoom& room) :
        socket_(std::move(socket)), room_(room) {
}

void ChatSession::Start() {
    room_.Join(shared_from_this());
    ReadHeader();
}

void ChatSession::Deliver(const ChatMessage& msg) {
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress) {
        Write();
    }
}

void ChatSession::ReadHeader() {
    auto self(shared_from_this());
    boost::asio::async_read(socket_,
            boost::asio::buffer(read_msg_.Data(), ChatMessage::header_length),
            [this, self](boost::system::error_code ec, std::size_t /*length*/)
            {
                if (!ec && read_msg_.DecodeHeader())
                {
                    ReadBody();
                }
                else
                {
                    room_.Leave(shared_from_this());
                }
            });
}

void ChatSession::ReadBody() {
    auto self(shared_from_this());
    boost::asio::async_read(socket_,
            boost::asio::buffer(read_msg_.Body(), read_msg_.BodyLength()),
            [this, self](boost::system::error_code ec, std::size_t /*length*/)
            {
                if (!ec)
                {
                    room_.Deliver(read_msg_);
                    ReadHeader();
                }
                else
                {
                    room_.Leave(shared_from_this());
                }
            });
}

void ChatSession::Write() {
    auto self(shared_from_this());
    boost::asio::async_write(socket_,
            boost::asio::buffer(write_msgs_.front().Data(),
                    write_msgs_.front().Lenght()),
            [this, self](boost::system::error_code ec, std::size_t /*length*/)
            {
                if (!ec)
                {
                    write_msgs_.pop_front();
                    if (!write_msgs_.empty())
                    {
                        Write();
                    }
                }
                else
                {
                    room_.Leave(shared_from_this());
                }
            });
}
}

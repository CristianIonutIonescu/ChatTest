/**
 * @file ChatClient.cpp
 *
 * @author c.ionescu@iquestgroup.com
 * @copyright (c) 2016 iQuest Group
 */

#include "ChatClient.h"
#include <iostream>

using boost::asio::ip::tcp;

ChatClient::ChatClient(boost::asio::io_service& io_service,
        tcp::resolver::iterator endpoint_iterator, std::string user_name) :
        io_service_(io_service), socket_(io_service), user_name_(user_name) {
    Connect(endpoint_iterator);
}

void ChatClient::Write(const ChatMessage& msg) {
    io_service_.post([this, msg]()
    {
        bool write_in_progress = !write_msgs_.empty();
        write_msgs_.push_back(msg);
        if (!write_in_progress) {
            Write();
        }
    });
}

void ChatClient::Close() {
    io_service_.post([this]() {socket_.close();});
}

void ChatClient::Connect(tcp::resolver::iterator endpoint_iterator) {
    boost::asio::async_connect(socket_, endpoint_iterator,
            [this](boost::system::error_code ec, tcp::resolver::iterator)
            {
                if (!ec) {
                    ReadHeader();
                }
            });
}

void ChatClient::ReadHeader() {
    boost::asio::async_read(socket_,
            boost::asio::buffer(read_msg_.Data(), ChatMessage::header_length),
            [this](boost::system::error_code ec, std::size_t /*length*/)
            {
                if (!ec && read_msg_.DecodeHeader()) {
                    ReadBody();
                } else {
                    socket_.close();
                }
            });
}

void ChatClient::ReadBody() {
    boost::asio::async_read(socket_,
            boost::asio::buffer(read_msg_.Body(), read_msg_.BodyLength()),
            [this](boost::system::error_code ec, std::size_t /*length*/)
            {
                if (!ec) {
                    std::cout.write(read_msg_.Body(), read_msg_.BodyLength());
                    std::cout << "\n";
                    ReadHeader();
                } else {
                    socket_.close();
                }
            });
}

void ChatClient::Write() {
    boost::asio::async_write(socket_,
            boost::asio::buffer(write_msgs_.front().Data(),
                    write_msgs_.front().Lenght()),
            [this](boost::system::error_code ec, std::size_t /*length*/)
            {
                if (!ec) {
                    write_msgs_.pop_front();
                    if (!write_msgs_.empty()) {
                        Write();
                    }
                } else {
                    socket_.close();
                }
            });
}

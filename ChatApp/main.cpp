/**
 * @file main.cpp
 *
 * @author c.ionescu@iquestgroup.com
 * @copyright (c) 2016 iQuest Group
 */

#include "Sources/ChatClient.h"

#include <cstdlib>
#include <thread>
#include <iostream>
#include <string>
#include <unordered_map>

int main(int argc, char* argv[]) {
    try {
        if (argc != 4) {
            std::cerr << "Usage: chat_client <host> <port>\n";
            return 1;
        }

        boost::asio::io_service io_service;

        tcp::resolver resolver(io_service);
        auto endpoint_iterator = resolver.resolve( { argv[1], argv[2] });
        ChatClient client(io_service, endpoint_iterator, argv[3]);

        std::thread t([&io_service]() {io_service.run();});

        char line[ChatMessage::max_body_length + 1];
        while (std::cin.getline(line, ChatMessage::max_body_length + 1)) {
            ChatMessage msg;
            std::string content = std::string(argv[3]) + ":" + std::string(line);
            msg.BodyLength(content.size());
            std::memcpy(msg.Body(), content.c_str(), msg.BodyLength());
            msg.EncodeHeader();
            client.Write(msg);
        }

        client.Close();
        t.join();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}


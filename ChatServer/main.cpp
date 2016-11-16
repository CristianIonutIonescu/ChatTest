/**
 * @file main.cpp
 *
 * @author c.ionescu@iquestgroup.com
 * @copyright (c) 2016 iQuest Group
 */

#include <cstdlib>
#include <iostream>
#include <list>
#include <boost/asio.hpp>

#include "Sources/ChatServer.h"

int main(int argc, char* argv[]) {
    try {
        if (argc < 2) {
            std::cerr << "Usage: chat_server <port> [<port> ...]\n";
            return 1;
        }

        boost::asio::io_service io_service;
        using boost::asio::ip::tcp;

        std::list<server::ChatServer> servers;
        for (int i = 1; i < argc; ++i) {
            tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[i]));
            servers.emplace_back(io_service, endpoint);
        }
        std::cout << "Servers running.." << std::endl;
        io_service.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}

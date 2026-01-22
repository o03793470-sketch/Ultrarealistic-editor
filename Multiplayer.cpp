#pragma once
#include <iostream>
#include <string>

struct Multiplayer {
    void SetupServer(int port) {
        std::cout << "Setting up multiplayer server on port " << port << std::endl;
    }

    void ConnectClient(const std::string& ip, int port) {
        std::cout << "Connecting client to " << ip << ":" << port << std::endl;
    }
};
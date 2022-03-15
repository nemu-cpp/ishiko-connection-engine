/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_ISHIKOCONNECTIONENGINE_ISHIKOSERVER_HPP_
#define _NEMU_CPP_ISHIKOCONNECTIONENGINE_ISHIKOSERVER_HPP_

#include <Nemu/Core.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/Networking.hpp>
#include <thread>

namespace Nemu
{

class IshikoServer : public Server
{
public:
    IshikoServer(Ishiko::Networking::IPv4Address address, Ishiko::Networking::Port port, Ishiko::Error& error);

    void start() override;
    void stop() override;
    void join() override;

    bool isRunning() const override;

private:
    Ishiko::Networking::TCPServerSocket m_socket;
    std::thread m_acceptThread;
};

}

#endif

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_ISHIKOCONNECTIONENGINE_ISHIKOSINGLECONNECTIONSERVER_HPP_
#define _NEMU_CPP_ISHIKOCONNECTIONENGINE_ISHIKOSINGLECONNECTIONSERVER_HPP_

#include <Nemu/Core.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/Networking.hpp>
#include <atomic>
#include <thread>

namespace Nemu
{

class IshikoSingleConnectionServer : public Server
{
public:
    IshikoSingleConnectionServer(Ishiko::IPv4Address address, Ishiko::Port port, Ishiko::Error& error);

    void start() override;
    void stop() override;
    void join() override;

    bool isRunning() const override;

    const Ishiko::TCPServerSocket& socket() const;

private:
    Ishiko::NetworkingLibraryInitialization m_init;
    Ishiko::TCPServerSocket m_socket;
    std::thread m_acceptThread;
    std::atomic<bool> m_stop;
};

}

#endif

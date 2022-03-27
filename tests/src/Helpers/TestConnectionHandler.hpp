/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_ISHIKOCONNECTIONENGINE_TESTS_HELPERS_TESTCONNECTIONHANDLER_HPP_
#define _NEMU_CPP_ISHIKOCONNECTIONENGINE_TESTS_HELPERS_TESTCONNECTIONHANDLER_HPP_

#include <Nemu/Core.hpp>

class TestConnectionHandler : public Nemu::Server::ConnectionHandler
{
public:
    void onConnection(const Nemu::WebRequest& request, Nemu::WebResponseBuilder& response) override;
};

#endif

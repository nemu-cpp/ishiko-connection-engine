/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTCONNECTIONHANDLER_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTCONNECTIONHANDLER_HPP_

#include <Nemu/WebFramework.hpp>

// TODO: do I still need thisclass since I now only do web requests
class TestConnectionHandler : public Nemu::Server::ConnectionHandler
{
public:
    void onConnection(Nemu::Connection& connection) override;
};

#endif

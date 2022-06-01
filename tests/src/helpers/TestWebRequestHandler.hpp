/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTWEBREQUESTHANDLER_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTWEBREQUESTHANDLER_HPP_

#include <Nemu/WebFramework.hpp>

class TestWebRequestHandler : public Nemu::WebRequestHandler
{
public:
    void run(const Nemu::WebRequest& request, Nemu::WebResponseBuilder& response, Ishiko::Logger& logger) override;
};

#endif

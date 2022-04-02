/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTWEBREQUEST_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTWEBREQUEST_HPP_

#include "Nemu/WebFramework/WebRequest.hpp"
#include <string>

// TODO: I don't need this anymore since WebRequest isn't virtual anymore
class TestWebRequest : public Nemu::WebRequest
{
public:
    TestWebRequest(std::string uri);

private:
    std::string m_uri;
};

#endif

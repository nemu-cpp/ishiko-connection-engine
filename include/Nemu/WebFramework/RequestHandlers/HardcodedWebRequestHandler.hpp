/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_REQUESTHANDLERS_HARDCODEDWEBREQUESTHANDLER_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_REQUESTHANDLERS_HARDCODEDWEBREQUESTHANDLER_HPP_

#include "../WebRequestHandler.hpp"
#include <string>

namespace Nemu
{

class HardcodedWebRequestHandler : public WebRequestHandler
{
public:
    HardcodedWebRequestHandler(unsigned int statusCode, const char* responseBody);

    void run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger) override;

private:
    unsigned int m_statusCode;
    std::string m_responseBody;
};

}

#endif

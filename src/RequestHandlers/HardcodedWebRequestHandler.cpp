/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "RequestHandlers/HardcodedWebRequestHandler.hpp"

using namespace Ishiko;

namespace Nemu
{

HardcodedWebRequestHandler::HardcodedWebRequestHandler(unsigned int statusCode, const char* responseBody)
    : m_statusCode(statusCode), m_responseBody(responseBody)
{
}

void HardcodedWebRequestHandler::run(const WebRequest& request, WebResponseBuilder& response, Logger& logger)
{
    response.setStatus(m_statusCode);
    response.body() = m_responseBody;
}

}

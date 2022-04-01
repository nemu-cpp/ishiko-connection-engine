/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "RequestHandlers/FunctionWebRequestHandler.hpp"

using namespace Ishiko;

namespace Nemu
{

FunctionWebRequestHandler::FunctionWebRequestHandler(RequestHandlerFunction handler)
    : m_handler(handler)
{
}

FunctionWebRequestHandler::FunctionWebRequestHandler(RequestHandlerFunction handler, std::shared_ptr<void> handlerData)
    : m_handler(handler), m_handlerData(handlerData)
{
}

void FunctionWebRequestHandler::run(const WebRequest& request, WebResponseBuilder& response, Logger& logger)
{
    m_handler(request, response, m_handlerData.get(), logger);
}

}

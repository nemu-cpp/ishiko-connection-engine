/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "RequestHandlers/ViewWebRequestHandler.hpp"

using namespace Nemu;

ViewWebRequestHandler::ViewWebRequestHandler()
{
}

void ViewWebRequestHandler::run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger)
{
    response.view(request.url().path(), m_context);
}

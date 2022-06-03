/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "RequestHandlers/ViewWebRequestHandler.hpp"

using namespace Nemu;

std::string ViewWebRequestHandler::PrefixMappingCallbacks::getView(const WebRequest& request,
    Ishiko::Error& error) const
{
    return request.url().path();
}

ViewWebRequestHandler::ViewWebRequestHandler(const Callbacks& callbacks)
    : m_callbacks(callbacks)
{
}

ViewWebRequestHandler::ViewWebRequestHandler(const Callbacks& callbacks, std::string layout)
    : m_callbacks(callbacks), m_layout(std::move(layout))
{
}

void ViewWebRequestHandler::run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger)
{
    // TODO: handle errors
    Ishiko::Error error;
    if (m_layout)
    {
        response.view(m_callbacks.getView(request, error), m_context, *m_layout);
    }
    else
    {
        response.view(m_callbacks.getView(request, error), m_context);
    }
}

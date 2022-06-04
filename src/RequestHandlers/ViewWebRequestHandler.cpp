/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "RequestHandlers/ViewWebRequestHandler.hpp"
#include <Ishiko/Text.hpp>

using namespace Nemu;

ViewWebRequestHandler::PrefixMappingCallbacks::PrefixMappingCallbacks(std::string urlPathPrefix,
    std::string contentPrefix)
    : m_urlPathPrefix(std::move(urlPathPrefix)), m_contentPrefix(std::move(contentPrefix))
{
}

std::string ViewWebRequestHandler::PrefixMappingCallbacks::getView(const WebRequest& request, Ishiko::Error& error)
{
    std::string result = request.url().path();
    if (!m_urlPathPrefix.empty() || !m_contentPrefix.empty())
    {
        if (Ishiko::ASCII::RemovePrefix(m_urlPathPrefix, result))
        {
            result.insert(result.begin(), m_contentPrefix.begin(), m_contentPrefix.end());
        }
        else
        {
            // TODO: this needs to be an error! Security risk, although the routing should prevent this in the first
            // place
        }
    }
    return result;
}

ViewWebRequestHandler::ViewWebRequestHandler(Callbacks& callbacks)
    : m_callbacks(callbacks)
{
}

ViewWebRequestHandler::ViewWebRequestHandler(Callbacks& callbacks, std::string layout)
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

const MapViewContext& ViewWebRequestHandler::context() const noexcept
{
    return m_context;
}

MapViewContext& ViewWebRequestHandler::context() noexcept
{
    return m_context;
}

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "RequestHandlers/ViewWebRequestHandler.hpp"
#include <Ishiko/Text.hpp>

using namespace Nemu;

boost::optional<std::string> ViewWebRequestHandler::Callbacks::getProfile(const WebRequest& request,
    Ishiko::Error& error)
{
    return boost::optional<std::string>();
}

boost::optional<std::string> ViewWebRequestHandler::Callbacks::getLayout(const WebRequest& request,
    Ishiko::Error& error)
{
    return boost::optional<std::string>();
}

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

ViewWebRequestHandler::DeclarativeCallbacks::DeclarativeCallbacks(const char* profile, const char* layout,
    const char* urlPathPrefix, const char* contentPrefix)
    : PrefixMappingCallbacks(urlPathPrefix, contentPrefix)
{
    if (profile)
    {
        m_profile = profile;
    }
    if (layout)
    {
        m_layout = layout;
    }
}

ViewWebRequestHandler::DeclarativeCallbacks::DeclarativeCallbacks(boost::optional<std::string> profile,
    boost::optional<std::string> layout, std::string urlPathPrefix, std::string contentPrefix)
    : m_profile(std::move(profile)), m_layout(std::move(layout)), PrefixMappingCallbacks(urlPathPrefix, contentPrefix)
{
}

boost::optional<std::string> ViewWebRequestHandler::DeclarativeCallbacks::getProfile(const WebRequest& request,
    Ishiko::Error& error)
{
    return m_profile;
}

boost::optional<std::string> ViewWebRequestHandler::DeclarativeCallbacks::getLayout(const WebRequest& request,
    Ishiko::Error& error)
{
    return m_layout;
}

ViewWebRequestHandler::ViewWebRequestHandler(Callbacks& callbacks)
    : m_callbacks(callbacks)
{
}

void ViewWebRequestHandler::run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger)
{
    // TODO: handle errors
    Ishiko::Error error;
    boost::optional<std::string> profile = m_callbacks.getProfile(request, error);
    boost::optional<std::string> layout = m_callbacks.getLayout(request, error);
    if (profile)
    {
        if (layout)
        {
            response.view(*profile, m_callbacks.getView(request, error), m_context, *layout);
        }
        else
        {
            response.view(*profile, m_callbacks.getView(request, error), m_context);
        }
    }
    else
    {
        if (layout)
        {
            response.view(m_callbacks.getView(request, error), m_context, *layout);
        }
        else
        {
            response.view(m_callbacks.getView(request, error), m_context);
        }
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

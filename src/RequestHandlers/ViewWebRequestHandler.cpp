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

ViewWebRequestHandler::DeclarativeCallbacks::PrefixMapping::PrefixMapping(std::string inputPrefix,
    std::string outputPrefix)
    : m_inputPrefix(std::move(inputPrefix)), m_outputPrefix(std::move(outputPrefix))
{
}

std::string ViewWebRequestHandler::DeclarativeCallbacks::PrefixMapping::getOutput(const std::string& input) const
{
    std::string result = input;
    if (!m_inputPrefix.empty() || !m_outputPrefix.empty())
    {
        if (Ishiko::ASCII::RemovePrefix(m_inputPrefix, result))
        {
            result.insert(result.begin(), m_outputPrefix.begin(), m_outputPrefix.end());
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
    ResolutionMechanism view)
    : m_view(std::move(view))
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
    boost::optional<std::string> layout, ResolutionMechanism view)
    : m_profile(std::move(profile)), m_layout(std::move(layout)), m_view(std::move(view))
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

std::string ViewWebRequestHandler::DeclarativeCallbacks::getView(const WebRequest& request, Ishiko::Error& error)
{
    switch (m_view.which())
    {
    case 0:
        return boost::get<std::string>(m_view);

    case 1:
        return boost::get<PrefixMapping>(m_view).getOutput(request.url().path());

    default:
        // TODO: impossible
        return "";
    }
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

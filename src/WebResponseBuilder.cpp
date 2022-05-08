/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "WebResponseBuilder.hpp"

using namespace Nemu;

WebResponseBuilder::WebResponseBuilder()
    : m_response(Ishiko::HTTPStatusCode::internalServerError), m_views(nullptr)
{
    // TODO: this doesn't work as the user would be left with specifying all the right headers. Do I assume some default?
}

void WebResponseBuilder::setStatus(unsigned int status)
{
    m_response.setStatusCode(status);
}
    
void WebResponseBuilder::setDateHeader(const Ishiko::UTCTime& time)
{
    m_response.setDateHeader(time);
}

std::string& WebResponseBuilder::body()
{
    return m_body;
}

std::string WebResponseBuilder::toString() const
{
    // TODO: wasteful
    Ishiko::HTTPResponse response(m_response);
    response.setBody(m_body);
    return response.toString();
}

void WebResponseBuilder::view(const std::string& view, ViewContext& context)
{
    body() = m_views->engine().render(view, context);
}

void WebResponseBuilder::view(const std::string& view, ViewContext& context, const std::string& layout)
{
    body() = m_views->engine().render(view, context, layout);
}

void WebResponseBuilder::redirect()
{
    // TODO
}

void WebResponseBuilder::state()
{
    // TODO
}

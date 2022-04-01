/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "WebResponseBuilder.hpp"

using namespace Ishiko;
using namespace std;

namespace Nemu
{

WebResponseBuilder::WebResponseBuilder()
    : m_response(HTTPStatusCode::internalServerError), : m_views(nullptr)
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

string& WebResponseBuilder::body()
{
    return m_body;
}

string WebResponseBuilder::toString() const
{
    // TODO: wasteful
    HTTPResponse response(m_response);
    response.setBody(m_body);
    return response.toString();
}

void WebResponseBuilder::view(const std::string& viewName)
{
    body() = m_views->engine().render();
}

void WebResponseBuilder::redirect()
{
}

void WebResponseBuilder::state()
{
}

}

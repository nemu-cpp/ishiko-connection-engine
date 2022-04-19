/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "WebRequest.hpp"

namespace Nemu
{

WebRequest::WebRequest()
    : m_url("")
{
}

WebRequest::WebRequest(Ishiko::URL url)
    : m_url(std::move(url))
{
}

const Ishiko::URL& WebRequest::url() const
{
    return m_url;
}

void WebRequest::onRequestURI(boost::string_view data)
{
    m_url = data.to_string();
}

}

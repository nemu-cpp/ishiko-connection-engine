/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "WebRequest.hpp"

using namespace boost;
using namespace std;

namespace Nemu
{

WebRequest::WebRequest(string uri)
    : m_uri(std::move(uri))
{
}

string WebRequest::URI() const
{
    return m_uri;
}

void WebRequest::onRequestURI(string_view data)
{
    m_uri = data.to_string();
}

}

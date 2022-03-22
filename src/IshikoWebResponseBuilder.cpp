/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#include "IshikoWebResponseBuilder.hpp"

using namespace Ishiko;
using namespace std;

namespace Nemu
{

IshikoWebResponseBuilder::IshikoWebResponseBuilder(const Views& views)
    : WebResponseBuilder(views), m_response(HTTPStatusCode::internalServerError)
{
    // TODO: this doesn't work as the user would be left with specifying all the right headers. Do I assume some default?
}

void IshikoWebResponseBuilder::setStatus(unsigned int status)
{
    m_response.setStatusCode(status);
}
    
string& IshikoWebResponseBuilder::body()
{
    return m_body;
}

string IshikoWebResponseBuilder::toString() const
{
    // TODO: wasteful
    HTTPResponse response(m_response);
    response.setBody(m_body);
    return response.toString();
}

}

/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "Route.hpp"

using namespace Ishiko;
using namespace std;

namespace Nemu
{

Route::Route(const string& pathPattern, shared_ptr<WebRequestHandler> handler)
    : m_pathPattern(pathPattern), m_handler(handler)
{
}

const string& Route::pathPattern() const
{
    return m_pathPattern;
}

WebRequestHandler& Route::requestHandler() const
{
    return *m_handler;
}

void Route::runHandler(const WebRequest& request, WebResponseBuilder& response, Logger& logger) const
{
    m_handler->run(request, response, logger);
}

}

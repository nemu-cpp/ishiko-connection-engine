/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "WebApplication.hpp"

using namespace Ishiko;
using namespace std;

namespace Nemu
{

WebApplication::ConnectionHandler::ConnectionHandler(WebApplication& owner)
    : m_owner(owner)
{
}

void WebApplication::ConnectionHandler::onConnection(const WebRequest& request, WebResponseBuilder& responseBuilder)
{
    responseBuilder.m_views = &m_owner.m_views;
    const Route& route = m_owner.m_routes->match(request.URI());
    route.runHandler(request, responseBuilder, m_owner.m_logger);
}

WebApplication::WebApplication(shared_ptr<Server> server, Logger& logger, Error& error)
    : Application(logger), m_connectionHandler(*this), m_routes(std::make_shared<Routes>())
{
    server->m_connectionHandler = &m_connectionHandler;
    server->m_logger = &logger;
    servers().append(server);
}

WebApplication::WebApplication(shared_ptr<Server> server, Logger& logger, shared_ptr<Routes> routes, Error& error)
    : Application(logger), m_connectionHandler(*this), m_routes(routes)
{
    server->m_connectionHandler = &m_connectionHandler;
    server->m_logger = &logger;
    servers().append(server);
}

Routes& WebApplication::routes()
{
    return *m_routes;
}

Views& WebApplication::views()
{
    return m_views;
}

}

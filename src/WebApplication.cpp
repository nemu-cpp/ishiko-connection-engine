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

WebApplication::RequestHandler::RequestHandler(WebApplication& owner)
    : m_owner(owner)
{
}

void WebApplication::RequestHandler::run(const WebRequest& request, WebResponseBuilder& response, Logger& logger)
{
    response.m_views = &m_owner.m_views;
    const Route& route = m_owner.m_routes->match(request.url().path());
    route.runHandler(request, response, m_owner.m_logger);
}

WebApplication::WebApplication(shared_ptr<WebServer> server, Logger& logger)
    : Application(logger), m_requestHandler(*this), m_routes(std::make_shared<Routes>())
{
    server->m_requestHandler = &m_requestHandler;
    servers().append(server);
}

WebApplication::WebApplication(shared_ptr<WebServer> server, Logger& logger, Error& error) noexcept
    : Application(logger), m_requestHandler(*this), m_routes(std::make_shared<Routes>())
{
    server->m_requestHandler = &m_requestHandler;
    servers().append(server);
}

WebApplication::WebApplication(shared_ptr<WebServer> server, Logger& logger, shared_ptr<Routes> routes, Error& error)
    : Application(logger), m_requestHandler(*this), m_routes(routes)
{
    server->m_requestHandler = &m_requestHandler;
    servers().append(server);
}

const Routes& WebApplication::routes() const noexcept
{
    return *m_routes;
}

Routes& WebApplication::routes() noexcept
{
    return *m_routes;
}

Views& WebApplication::views()
{
    return m_views;
}

}

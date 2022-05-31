/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_WEBAPPLICATION_HPP_
#define _NEMU_CPP_CORE_WEBAPPLICATION_HPP_

#include "Routes.hpp"
#include "Views.hpp"
#include "WebServer.hpp"
#include <Ishiko/Errors.hpp>
#include <Ishiko/Logging.hpp>
#include <vector>
#include <memory>

namespace Nemu
{

/// An application that serves requests over the HTTP or HTTPS protocol.
class WebApplication : public Application
{
public:
    /// Constructor.
    WebApplication(std::shared_ptr<WebServer> server, Ishiko::Logger& logger);
    // TODO: the shared_ptr violates the no except nature of this function
    WebApplication(std::shared_ptr<WebServer> server, Ishiko::Logger& logger, Ishiko::Error& error) noexcept;
    WebApplication(std::shared_ptr<WebServer> server, Ishiko::Logger& logger, std::shared_ptr<Routes> routes,
        Ishiko::Error& error);

    /// Returns the routes.
    const Routes& routes() const noexcept;
    Routes& routes() noexcept;

    Views& views();

private:
    class RequestHandler : public WebRequestHandler
    {
    public:
        RequestHandler(WebApplication& owner);

        void run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger) override;

    private:
        WebApplication& m_owner;
    };

    RequestHandler m_requestHandler;
    std::shared_ptr<Routes> m_routes;
    Views m_views;
};

}

#endif

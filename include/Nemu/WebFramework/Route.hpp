/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_ROUTE_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_ROUTE_HPP_

#include "WebRequest.hpp"
#include "WebResponseBuilder.hpp"
#include "WebRequestHandler.hpp"
#include <Ishiko/Logging.hpp>
#include <memory>
#include <string>

namespace Nemu
{

/// A request routing specification for a web application.
class Route
{
public:
    /// Constructor.
    /**
        @param pathPattern The handler handles requests that match this pattern.
        @param handler The request handler.
    */
    Route(const std::string& pathPattern, std::shared_ptr<WebRequestHandler> handler);
    
    /// Returns the path pattern.
    const std::string& pathPattern() const;

    WebRequestHandler& requestHandler() const;

    void runHandler(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger) const;

private:
    std::string m_pathPattern;
    std::shared_ptr<WebRequestHandler> m_handler;
};

}

#endif

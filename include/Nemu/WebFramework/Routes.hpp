/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_ROUTES_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_ROUTES_HPP_

#include "Route.hpp"
#include <vector>
#include <string>

namespace Nemu
{

/// A sequence of routes.
/**
    In addition to the routes explicitly added to the sequence a default route is also stored. It is returned by the
    Routes::match function if no match is found.

    This class is used by the Application class to store the route specifications. There should usually be no need to
    create an instance of this class yourself.
*/
class Routes
{
public:
    /// Constructor.
    Routes();

    /// Appends a route to the sequence.
    /**
        @param route The route to add.
    */
    void append(const Route& route);

    /// Finds the first route in the sequence that matches the path.
    /**
        If no match is found the default route is returned.
        @param path The path to match.
    */
    const Route& match(const std::string& path) const;

    const Route& defaultRoute() const;
    void setDefaultRoute(const Route& route);

private:
    std::vector<Route> m_routes;
    Route m_defaultRoute;
};

}

#endif

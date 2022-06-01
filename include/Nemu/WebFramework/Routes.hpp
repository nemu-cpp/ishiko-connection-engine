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

    size_t size() const noexcept;
    const Route& at(size_t pos) const;

    /// Adds a route to the sequence.
    /**
        @param route The route to add.
    */
    // TODO: argument isn't really const due to the shared pointer unless I can guarantee it's immutable?
    void add(const Route& route);
    void add(std::vector<Route>& routes);
    // TODO: can these be const_iterator
    void add(std::vector<Route>::iterator begin, std::vector<Route>::iterator end);

    // TODO: this should match URLs including host and scheme
    /// Finds the first route in the sequence that matches the path.
    /**
        If no match is found the default route is returned.
        @param path The path to match.
    */
    const Route& match(const std::string& path) const;

    const Route& defaultRoute() const;
    void setDefaultRoute(const Route& route);

private:
    std::vector<Route> m_exactMatchRoutes;
    std::vector<Route> m_prefixMatchRoutes;
    Route m_defaultRoute;
};

}

#endif

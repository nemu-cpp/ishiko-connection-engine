/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "Routes.hpp"
#include "RequestHandlers/HardcodedWebRequestHandler.hpp"

using namespace Ishiko;
using namespace std;

namespace Nemu
{

Routes::Routes()
    : m_defaultRoute("", make_shared<HardcodedWebRequestHandler>(404, "The requested resource was not found"))
{
}

void Routes::append(const Route& route)
{
    m_routes.push_back(route);
}

const Route& Routes::match(const std::string& path) const
{
    for (const Route& route : m_routes)
    {
        if (route.path() == path)
        {
            return route;
        }
    }
    return m_defaultRoute;
}

const Route& Routes::defaultRoute() const
{
    return m_defaultRoute;
}

void Routes::setDefaultRoute(const Route& route)
{
    m_defaultRoute = route;
}

}

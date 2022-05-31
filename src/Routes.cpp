/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "Routes.hpp"
#include "RequestHandlers/HardcodedWebRequestHandler.hpp"

using namespace Nemu;

Routes::Routes()
    : m_defaultRoute("*", std::make_shared<HardcodedWebRequestHandler>(404, "The requested resource was not found"))
{
}

size_t Routes::size() const noexcept
{
    return (m_exactMatchRoutes.size() + m_prefixMatchRoutes.size() + 1);
}

const Route& Routes::at(size_t pos) const
{
    if (pos < m_exactMatchRoutes.size())
    {
        return m_exactMatchRoutes[pos];
    }
    else if (pos < (m_exactMatchRoutes.size() + m_prefixMatchRoutes.size()))
    {
        return m_prefixMatchRoutes[pos - m_exactMatchRoutes.size()];
    }
    else if (pos < (m_exactMatchRoutes.size() + m_prefixMatchRoutes.size() + 1))
    {
        return m_defaultRoute;
    }
}

void Routes::append(const Route& route)
{
    const std::string& pattern = route.pathPattern();
    if (!pattern.empty() && (pattern.back() == '*'))
    {
        m_prefixMatchRoutes.push_back(route);
    }
    else
    {
        m_exactMatchRoutes.push_back(route);
    }
}

const Route& Routes::match(const std::string& path) const
{
    // TOD: a hashmap would be ideal for this I think
    for (const Route& route : m_exactMatchRoutes)
    {
        if (route.pathPattern() == path)
        {
            return route;
        }
    }
    for (const Route& route : m_prefixMatchRoutes)
    {
        const std::string& pattern = route.pathPattern();
        if (strncmp(path.c_str(), pattern.c_str(), pattern.size() - 1) == 0)
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

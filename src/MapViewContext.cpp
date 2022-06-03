/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "MapViewContext.hpp"
#include <Nemu/Core.hpp>

using namespace Nemu;

void MapViewContext::getValue(const std::string& variable, std::string& result, Ishiko::Error error)
{
    std::map<std::string, std::string>::const_iterator it = m_map.find(variable);
    if (it != m_map.end())
    {
        result.append(it->second);
    }
    else
    {
        // TODO: better error
        Fail(error, NemuErrorCategory::eGeneric, "", __FILE__, __LINE__);
    }
}

std::map<std::string, std::string>& MapViewContext::map() noexcept
{
    return m_map;
}

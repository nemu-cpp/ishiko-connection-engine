/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "MapViewContext.hpp"
#include <Nemu/Core.hpp>

using namespace Nemu;

ViewContext::Value MapViewContext::getValue(const std::string& variable, Ishiko::Error& error)
{
    std::map<std::string, Value>::const_iterator it = m_map.find(variable);
    if (it != m_map.end())
    {
        return it->second;
    }
    else
    {
        // TODO: better error
        Fail(error, NemuErrorCategory::eGeneric, "", __FILE__, __LINE__);
        return Value();
    }
}

const std::map<std::string, ViewContext::Value> MapViewContext::toMap() const noexcept
{
    return m_map;
}

std::map<std::string, ViewContext::Value>& MapViewContext::map() noexcept
{
    return m_map;
}

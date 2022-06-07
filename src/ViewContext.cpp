/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "ViewContext.hpp"

using namespace Nemu;

ViewContext::Value::Value(const char* value)
    : boost::variant<std::string, Array, Map>(value)
{
}

ViewContext::Value::Value(const std::string& value)
    : boost::variant<std::string, Array, Map>(value)
{
}

ViewContext::Value::Value(std::string&& value)
    : boost::variant<std::string, Array, Map>(value)
{
}

ViewContext::Value::Value(const std::vector<Value>& value)
    : boost::variant<std::string, Array, Map>(value)
{
}

ViewContext::Value::Value(const std::map<std::string, Value>& value)
    : boost::variant<std::string, Array, Map>(value)
{
}

ViewContext::Value::Type ViewContext::Value::type() const
{
    return static_cast<ViewContext::Value::Type>(which());
}

const std::string& ViewContext::Value::asString() const
{
    return boost::get<std::string>(*this);
}

std::string& ViewContext::Value::asString()
{
    return boost::get<std::string>(*this);
}

const ViewContext::Value::Array& ViewContext::Value::asValueArray() const
{
    return boost::get<Array>(*this);
}

ViewContext::Value::Array& ViewContext::Value::asValueArray()
{
    return boost::get<Array>(*this);
}

const ViewContext::Value::Map& ViewContext::Value::asValueMap() const
{
    return boost::get<Map>(*this);
}

ViewContext::Value::Map& ViewContext::Value::asValueMap()
{
    return boost::get<Map>(*this);
}

bool ViewContext::Value::operator==(const Value& other) const noexcept
{
    const auto& arg1 = static_cast<const boost::variant<std::string, Array, Map>&>(*this);
    const auto& arg2 = static_cast<const boost::variant<std::string, Array, Map>&>(other);
    return (arg1 == arg2);
}

bool ViewContext::Value::operator!=(const Value& other) const noexcept
{
    // boost::variant provides == but not !=
    return !(*this == other);
}

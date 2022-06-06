/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "ViewContext.hpp"

using namespace Nemu;

ViewContext::Value::Value(const char* value)
    : boost::variant<std::string, std::vector<Value>, std::map<std::string, std::string>>(value)
{
}

ViewContext::Value::Value(const std::string& value)
    : boost::variant<std::string, std::vector<Value>, std::map<std::string, std::string>>(value)
{
}

ViewContext::Value::Value(std::string&& value)
    : boost::variant<std::string, std::vector<Value>, std::map<std::string, std::string>>(value)
{
}

ViewContext::Value::Value(const std::vector<Value>& value)
    : boost::variant<std::string, std::vector<Value>, std::map<std::string, std::string>>(value)
{
}

ViewContext::Value::Value(const std::map<std::string, std::string>& value)
    : boost::variant<std::string, std::vector<Value>, std::map<std::string, std::string>>(value)
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

const std::vector<ViewContext::Value>& ViewContext::Value::asValueArray() const
{
    return boost::get<std::vector<Value>>(*this);
}

const std::map<std::string, std::string>& ViewContext::Value::asStringMap() const
{
    return boost::get<std::map<std::string, std::string>>(*this);
}

bool ViewContext::Value::operator==(const Value& other) const noexcept
{
    const auto& arg1 =
        static_cast<const boost::variant<std::string, std::vector<Value>, std::map<std::string, std::string>>&>(*this);
    const auto& arg2 =
        static_cast<const boost::variant<std::string, std::vector<Value>, std::map<std::string, std::string>>&>(other);
    return (arg1 == arg2);
}

bool ViewContext::Value::operator!=(const Value& other) const noexcept
{
    // boost::variant provides == but not !=
    return !(*this == other);
}

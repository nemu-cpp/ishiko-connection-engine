/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "ViewContext.hpp"

using namespace Nemu;

ViewContext::Value::Value(const char* value)
    : boost::variant<std::string, std::vector<std::string>>(value)
{
}

ViewContext::Value::Value(const std::string& value)
    : boost::variant<std::string, std::vector<std::string>>(value)
{
}

ViewContext::Value::Value(std::string&& value)
    : boost::variant<std::string, std::vector<std::string>>(value)
{
}

ViewContext::Value::Value(const std::vector<std::string>& value)
    : boost::variant<std::string, std::vector<std::string>>(value)
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

const std::vector<std::string>& ViewContext::Value::asStringArray() const
{
    return boost::get<std::vector<std::string>>(*this);
}

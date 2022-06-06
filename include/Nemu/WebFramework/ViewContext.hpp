/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_VIEWCONTEXT_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_VIEWCONTEXT_HPP_

#include <boost/variant.hpp>
#include <Ishiko/Errors.hpp>
#include <map>
#include <string>
#include <vector>

namespace Nemu
{

class ViewContext
{
public:
    class Value : boost::variant<std::string, std::vector<std::string>>
    {
    public:
        enum class Type
        {
            string = 0,
            stringArray = 1
        };

        Value() = default;
        Value(const char* value);
        Value(const std::string & value);
        Value(std::string && value);
        Value(const std::vector<std::string>&value);

        Type type() const;
        const std::string& asString() const;
        const std::vector<std::string>& asStringArray() const;
    };

    // TODO: this will append the value to result, is it possible to have something even more generic so that this can
    // be as efficient as possible
    // TODO: it's more complicated than that as the value could be an array or an object
    virtual void getValue(const std::string& variable, std::string& result, Ishiko::Error error) = 0;

    // TODO: workaround until I can fix mustache or stop using it
    virtual const std::map<std::string, std::string> map() const noexcept = 0;
};

}

#endif

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
    class Value : boost::variant<std::string, std::vector<Value>, std::map<std::string, Value>>
    {
    public:
        typedef std::vector<Value> Array;
        typedef std::map<std::string, Value> Map;

        enum class Type
        {
            string = 0,
            valueArray = 1,
            valueMap = 2
        };

        Value() = default;
        Value(const char* value);
        Value(const std::string & value);
        Value(std::string && value);
        Value(const std::vector<Value>&value);
        Value(const std::map<std::string, Value>& value);

        Type type() const;
        const std::string& asString() const;
        std::string& asString();
        const Array& asValueArray() const;
        Array& asValueArray();
        const Map& asValueMap() const;
        Map& asValueMap();

        bool operator==(const Value& other) const noexcept;
        bool operator!=(const Value& other) const noexcept;
    };

    // TODO: this will append the value to result, is it possible to have something even more generic so that this can
    // be as efficient as possible
    // TODO: it's more complicated than that as the value could be an array or an object
    // TOOD: actually the solution is to return the value and have the value be something more abstract.
    virtual Value getValue(const std::string& variable, Ishiko::Error& error) = 0;

    // TODO: workaround until I can fix mustache or stop using it
    virtual const std::map<std::string, Value> toMap() const noexcept = 0;
};

}

#endif

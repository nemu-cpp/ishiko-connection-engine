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
    class Value : boost::variant<std::string, std::vector<std::string>, std::map<std::string, std::string>>
    {
    public:
        enum class Type
        {
            string = 0,
            // TODO: should I have valueArray and valueMap instead? I need to get some more feedback about actual usage
            // in templates before deciding
            stringArray = 1,
            // TODO: I can't have a nested ViewContext because it is an abstract class, I could have a pointer to a
            // ViewContext but I don't know if that is really what I want anyway. A map of values I may need though.
            stringMap = 2
        };

        Value() = default;
        Value(const char* value);
        Value(const std::string & value);
        Value(std::string && value);
        Value(const std::vector<std::string>&value);
        Value(const std::map<std::string, std::string>& value);

        Type type() const;
        const std::string& asString() const;
        const std::vector<std::string>& asStringArray() const;
        const std::map<std::string, std::string>& asStringMap() const;
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

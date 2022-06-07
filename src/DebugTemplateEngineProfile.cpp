/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "DebugTemplateEngineProfile.hpp"
#include <string>
#include <vector>

using namespace Nemu;

namespace
{

// TODO: remove recursion in this function
void WriteValue(const ViewContext::Value& value, std::string& output)
{
    switch (value.type())
    {
    case ViewContext::Value::Type::string:
        output.append("\"" + value.asString() + "\"");
        break;

    case ViewContext::Value::Type::valueArray:
        {
            output.append("[<ol>");
            for (const ViewContext::Value& v : value.asValueArray())
            {
                output.append("<li>\"");
                WriteValue(v, output);
                output.append("\"</li>");
            }
            output.append("</ol>]");
        }
        break;

    case ViewContext::Value::Type::valueMap:
        {
            output.append("{<ul>");
            for (const std::pair<std::string, ViewContext::Value>& v : value.asValueMap())
            {
                output.append("<li>\"" + v.first + "\": ");
                WriteValue(v.second, output);
                output.append("</li>");
            }
            output.append("</ul>}");
        }
        break;

    default:
        // TODO: error
        break;
    }
}

}

std::string DebugTemplateEngineProfile::render(const std::string& view, ViewContext& context,
    const std::string* layout)
{
    // TODO: I need to use a proper HTML generator for this for safe escaping in particular

    std::string result;

    result.append("<html><head><title>Nemu Debug View</title></head><body><h2>Arguments</h2><ul><li>view: \"");
    result.append(view);
    result.append("\"</li><li>layout: \"");
    if (layout)
    {
        result.append(*layout);
    }
    else
    {
        result.append("null");
    }
    result.append("\"</li></ul><h2>View Context</h2>");
    std::map<std::string, ViewContext::Value> map = context.toMap();
    
    result.append("{<ul>");

    // TODO: limit output size
    for (const std::pair<std::string, ViewContext::Value> item : map)
    {
        result.append("<li>\"");
        result.append(item.first);
        result.append("\": ");
        WriteValue(item.second, result);
        result.append("</li>");
    }

    result.append("</ul>}");
   
    result.append("</body>");

    return result;
}

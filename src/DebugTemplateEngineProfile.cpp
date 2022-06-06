/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "DebugTemplateEngineProfile.hpp"
#include <string>
#include <vector>

using namespace Nemu;

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
    if (map.empty())
    {
        result.append("Empty");
    }
    else
    {
        result.append("<ul>");

        // TODO: limit output size
        for (const std::pair<std::string, ViewContext::Value> item : map)
        {
            result.append("<li>\"");
            result.append(item.first);
            result.append("\": ");
            switch (item.second.type())
            {
            case ViewContext::Value::Type::string:
                result.append("\"" + item.second.asString() + "\"");
                break;

            case ViewContext::Value::Type::stringArray:
                {
                    result.append("[<ol>");
                    const std::vector<std::string>& array = item.second.asStringArray();
                    for (const std::string& str : array)
                    {
                        result.append("<li>\"" + str + "\"</li>");
                    }
                    result.append("</ol>]");
                }
                break;

            default:
                // TODO: error
                break;
            }
            result.append("</li>");
        }

        result.append("</ul>");
    }
    result.append("</body>");

    return result;
}

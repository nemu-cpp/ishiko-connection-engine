/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "DebugTemplateEngineProfile.hpp"

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
    if (context.map().empty())
    {
        result.append("Empty");
    }
    else
    {
        result.append("<ul>");

        // TODO: limit output size
        for (const std::pair<std::string, std::string> item : context.map())
        {
            result.append("<li>\"");
            result.append(item.first);
            result.append("\": \"");
            result.append(item.second);
            result.append("\"</li>");
        }

        result.append("</ul>");
    }
    result.append("</body>");

    return result;
}

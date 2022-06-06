/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "TestTemplateEngineProfile.hpp"

TestTemplateEngineProfile::TestTemplateEngineProfile(std::string text)
    : m_text(std::move(text))
{
}

std::string TestTemplateEngineProfile::render(const std::string& view, Nemu::ViewContext& context,
    const std::string* layout)
{
    m_receivedViews.push_back(view);
    if (layout)
    {
        m_receivedLayouts.push_back(*layout);
    }
    else
    {
        m_receivedLayouts.push_back("null");
    }
    std::string result = "<html><p>" + m_text + "</p><p>";
    // TODO: how to handle error? Should render take an error?
    Ishiko::Error error;
    result.append(context.getValue("text", error).asString());
    result += "</p></html>";
    return result;
}

const std::vector<std::string> TestTemplateEngineProfile::receivedViews() const
{
    return m_receivedViews;
}

const std::vector<std::string> TestTemplateEngineProfile::receivedLayouts() const
{
    return m_receivedLayouts;
}

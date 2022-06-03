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
    return ("<html>" + m_text + "</html>");
}

const std::vector<std::string> TestTemplateEngineProfile::receivedViews() const
{
    return m_receivedViews;
}

const std::vector<std::string> TestTemplateEngineProfile::receivedLayouts() const
{
    return m_receivedLayouts;
}

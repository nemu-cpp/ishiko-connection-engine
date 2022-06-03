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
    return ("<html>" + m_text + "</html>");
}

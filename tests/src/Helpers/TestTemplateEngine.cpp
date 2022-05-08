/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "TestTemplateEngine.hpp"

std::string TestTemplateEngine::render(const std::string& view, Nemu::ViewContext& context)
{
    m_view = view;
    return "<html></html>";
}

std::string TestTemplateEngine::render(const std::string& view, Nemu::ViewContext& context, const std::string& layout)
{
    m_view = view;
    return "<html></html>";
}

const std::string& TestTemplateEngine::view() const
{
    return m_view;
}

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTTEMPLATEENGINE_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTTEMPLATEENGINE_HPP_

#include "Nemu/WebFramework/TemplateEngine.hpp"
#include <string>

class TestTemplateEngine : public Nemu::TemplateEngine
{
public:
    std::string render(const std::string& view, Nemu::ViewContext& context) override;
    std::string render(const std::string& view, Nemu::ViewContext& context, const std::string& layout) override;

    const std::string& view() const;

private:
    std::string m_view;
};

#endif

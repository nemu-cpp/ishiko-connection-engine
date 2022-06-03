/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTTEMPLATEENGINEPROFILE_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTTEMPLATEENGINEPROFILE_HPP_

#include "Nemu/WebFramework/TemplateEngineProfile.hpp"
#include <string>

class TestTemplateEngineProfile : public Nemu::TemplateEngineProfile
{
public:
    TestTemplateEngineProfile(std::string text);

    std::string render(const std::string& view, Nemu::ViewContext& context, const std::string* layout) override;

private:
    std::string m_text;
};

#endif

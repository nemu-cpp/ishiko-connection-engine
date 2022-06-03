/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTTEMPLATEENGINEPROFILE_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTTEMPLATEENGINEPROFILE_HPP_

#include "Nemu/WebFramework/TemplateEngineProfile.hpp"
#include <string>
#include <vector>

class TestTemplateEngineProfile : public Nemu::TemplateEngineProfile
{
public:
    TestTemplateEngineProfile(std::string text);

    std::string render(const std::string& view, Nemu::ViewContext& context, const std::string* layout) override;

    const std::vector<std::string> receivedViews() const;
    const std::vector<std::string> receivedLayouts() const;

private:
    std::string m_text;
    std::vector<std::string> m_receivedViews;
    std::vector<std::string> m_receivedLayouts;
};

#endif

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTTEMPLATEENGINE_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTTEMPLATEENGINE_HPP_

#include "Nemu/WebFramework/TemplateEngine.hpp"
#include <Ishiko/Configuration.hpp>
#include <string>
#include <memory>

class TestTemplateEngine : public Nemu::TemplateEngine
{
public:
    std::shared_ptr<Nemu::TemplateEngineProfile> createProfile(
        const Ishiko::Configuration& configuration) const override;
};

#endif

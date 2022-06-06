/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "TestTemplateEngine.hpp"
#include "TestTemplateEngineProfile.hpp"

std::shared_ptr<Nemu::TemplateEngineProfile> TestTemplateEngine::createProfile(
    const Ishiko::Configuration& configuration) const
{
    return std::make_shared<TestTemplateEngineProfile>(configuration.value("text").asString());
}

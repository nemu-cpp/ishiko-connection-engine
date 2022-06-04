/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "DebugTemplateEngine.hpp"
#include "DebugTemplateEngineProfile.hpp"

using namespace Nemu;

std::shared_ptr<TemplateEngineProfile> DebugTemplateEngine::createProfile(
    const Ishiko::Configuration& configuration) const
{
    return std::make_shared<DebugTemplateEngineProfile>();
}

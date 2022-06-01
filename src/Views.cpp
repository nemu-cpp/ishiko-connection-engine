/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "Views.hpp"
#include <Ishiko/Configuration.hpp>

namespace Nemu
{

Views::Views()
{
}

Views::Views(std::shared_ptr<TemplateEngineProfile> defaultProfile)
    : m_defaultProfile(defaultProfile)
{
}

void Views::add(std::shared_ptr<TemplateEngine> engine)
{
    m_defaultProfile = engine->createProfile(Ishiko::Configuration());
}

TemplateEngineProfile& Views::defaultProfile()
{
    return *m_defaultProfile;
}

}

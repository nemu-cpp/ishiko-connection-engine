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

void Views::setDefaultProfile(std::shared_ptr<TemplateEngineProfile> profile)
{
    m_defaultProfile = profile;
}

void Views::set(const std::string& name, std::shared_ptr<TemplateEngineProfile> profile)
{
    m_profiles[name] = profile;
}

TemplateEngineProfile& Views::defaultProfile()
{
    return *m_defaultProfile;
}

TemplateEngineProfile& Views::profile(const std::string& name)
{
    return *m_profiles.at(name);
}

}

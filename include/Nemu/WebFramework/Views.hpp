/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_VIEWS_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_VIEWS_HPP_

#include "TemplateEngine.hpp"
#include "TemplateEngineProfile.hpp"
#include <map>
#include <memory>

namespace Nemu
{

/// A list of templating engines and their associated settings.
class Views
{
public:
    Views();
    Views(std::shared_ptr<TemplateEngineProfile> defaultProfile);

    void setDefaultProfile(std::shared_ptr<TemplateEngineProfile> profile);
    void set(const std::string& name, std::shared_ptr<TemplateEngineProfile> profile);

    TemplateEngineProfile& defaultProfile();
    TemplateEngineProfile& profile(const std::string& name);

private:
    std::shared_ptr<TemplateEngineProfile> m_defaultProfile;
    std::map<std::string, std::shared_ptr<TemplateEngineProfile>> m_profiles;
};

}

#endif

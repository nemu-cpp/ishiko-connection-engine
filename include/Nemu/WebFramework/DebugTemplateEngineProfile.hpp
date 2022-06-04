/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_DEBUGTEMPLATEENGINEPROFILE_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_DEBUGTEMPLATEENGINEPROFILE_HPP_

#include "TemplateEngineProfile.hpp"

namespace Nemu
{

class DebugTemplateEngineProfile : public TemplateEngineProfile
{
public:
    std::string render(const std::string& view, ViewContext& context, const std::string* layout) override;
};

}

#endif

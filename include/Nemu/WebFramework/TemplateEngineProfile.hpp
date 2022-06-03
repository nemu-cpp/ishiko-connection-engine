/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TEMPLATEENGINEPROFILE_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TEMPLATEENGINEPROFILE_HPP_

#include "ViewContext.hpp"
#include <string>

namespace Nemu
{

// TODO: this is a template engine with a specific set of options. What these options are is engine specific.
// TODO: TemplateEngine::createProfile acts as a factory.
class TemplateEngineProfile
{
public:
    virtual std::string render(const std::string& view, ViewContext& context, const std::string* layout) = 0;
};

}

#endif

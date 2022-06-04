/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_DEBUGTEMPLATEENGINE_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_DEBUGTEMPLATEENGINE_HPP_

#include "TemplateEngine.hpp"
#include <Ishiko/Configuration.hpp>
#include <memory>

namespace Nemu
{

class DebugTemplateEngine : public TemplateEngine
{
public:
    std::shared_ptr<TemplateEngineProfile> createProfile(const Ishiko::Configuration& configuration) const override;
};

}

#endif

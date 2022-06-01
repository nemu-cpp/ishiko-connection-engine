/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TEMPLATEENGINE_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TEMPLATEENGINE_HPP_

#include "TemplateEngineProfile.hpp"
#include <Ishiko/Configuration.hpp>
#include <memory>

namespace Nemu
{

/// Base class for classes that implement templating engines.
/**
    TODO: out of date comment since we now go via the Profile first.
    Templating engines are used by web applications to serve pages generated from templates. In Nemu such engines are
    registered with the Views instance stored in a WebApplication instance. They are invoked from the WebResponse::view
    function.
*/
class TemplateEngine
{
public:
    virtual std::shared_ptr<TemplateEngineProfile> createProfile(const Ishiko::Configuration& configuration) const = 0;
};

}

#endif

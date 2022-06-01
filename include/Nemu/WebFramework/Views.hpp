/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_VIEWS_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_VIEWS_HPP_

#include "TemplateEngine.hpp"
#include "TemplateEngineProfile.hpp"
#include <memory>

namespace Nemu
{

/// A list of templating engines and their associated settings.
class Views
{
public:
    Views();
    Views(std::shared_ptr<TemplateEngine> engine);

    // TODO: at the momment we only support one view engine but we plan to support more later
    void add(std::shared_ptr<TemplateEngine> engine);

    TemplateEngineProfile& defaultProfile();

private:
    std::shared_ptr<TemplateEngineProfile> m_engine;
};

}

#endif

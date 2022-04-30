/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "Views.hpp"

namespace Nemu
{

Views::Views()
{
}

Views::Views(std::shared_ptr<TemplateEngine> engine)
    : m_engine(engine)
{
}

TemplateEngine& Views::engine()
{
    return *m_engine;
}

}

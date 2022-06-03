/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_VIEWCONTEXT_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_VIEWCONTEXT_HPP_

#include <Ishiko/Errors.hpp>
#include <string>

namespace Nemu
{

class ViewContext
{
public:
    // TODO: this will append the value to result, is it possible to have something even more generic so that this can
    // be as efficient as possible
    virtual void getValue(const std::string& variable, std::string& result, Ishiko::Error error) = 0;
};

}

#endif

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_WEBREQUESTHANDLER_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_WEBREQUESTHANDLER_HPP_

#include "WebRequest.hpp"
#include "WebResponseBuilder.hpp"
#include <Ishiko/Logging.hpp>
#include <memory>

namespace Nemu
{

class WebRequestHandler
{
public:
    virtual void run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger) = 0;
};

}

#endif

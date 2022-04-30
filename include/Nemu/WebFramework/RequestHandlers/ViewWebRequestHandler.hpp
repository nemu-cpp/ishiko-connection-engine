/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_REQUESTHANDLERS_VIEWWEBREQUESTHANDLER_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_REQUESTHANDLERS_VIEWWEBREQUESTHANDLER_HPP_

#include "../WebRequestHandler.hpp"

namespace Nemu
{
    
class ViewWebRequestHandler : public WebRequestHandler
{
public:
    ViewWebRequestHandler();

    void run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger) override;

private:
    ViewContext m_context;
};

}

#endif

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_REQUESTHANDLERS_FUNCTIONWEBREQUESTHANDLER_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_REQUESTHANDLERS_FUNCTIONWEBREQUESTHANDLER_HPP_

#include "../WebRequestHandler.hpp"

namespace Nemu
{

class FunctionWebRequestHandler : public WebRequestHandler
{
public:
    // TODO: update comment
    /// The type definition for the request handlers.
    /**
        @param request The request that was received from the client.
        @param response This argument is used to build the response that will be returned to the client.
        @param handlerData Additional data required by the handler. This data can be stored in the route at construction
        time and retrieved with the Route::handlerData() accessor.
    */
    typedef void (*RequestHandlerFunction)(const WebRequest& request, WebResponseBuilder& response, void* handlerData,
        Ishiko::Logger& logger);

    template<class Callable> FunctionWebRequestHandler(Callable handler);
    FunctionWebRequestHandler(RequestHandlerFunction handler);
    FunctionWebRequestHandler(RequestHandlerFunction handler, std::shared_ptr<void> handlerData);

    void run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger) override;

private:
    // TODO: std::function and _data are redundant but before I change this I want to understand the performance implications better
    std::function<void(const WebRequest& request, WebResponseBuilder& response, void* handlerData, Ishiko::Logger& logger)> m_handler;
    std::shared_ptr<void> m_handlerData;
};

template<class Callable>
FunctionWebRequestHandler::FunctionWebRequestHandler(Callable handler)
    : m_handler(handler)
{
}

}

#endif

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_REQUESTHANDLERS_VIEWWEBREQUESTHANDLER_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_REQUESTHANDLERS_VIEWWEBREQUESTHANDLER_HPP_

#include "../WebRequestHandler.hpp"
#include <boost/optional.hpp>
#include <Ishiko/Errors.hpp>
#include <string>

namespace Nemu
{
    
class ViewWebRequestHandler : public WebRequestHandler
{
public:
    class Callbacks
    {
    public:
        virtual ~Callbacks() = default;

        virtual std::string getView(const WebRequest& request, Ishiko::Error& error) const = 0;
    };

    class PrefixMappingCallbacks : public Callbacks
    {
    public:
        std::string getView(const WebRequest& request, Ishiko::Error& error) const override;
    };

    ViewWebRequestHandler(const Callbacks& callbacks);
    ViewWebRequestHandler(const Callbacks& callbacks, std::string layout);

    void run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger) override;

private:
    const Callbacks& m_callbacks;
    boost::optional<std::string> m_layout;
    ViewContext m_context;
};

}

#endif

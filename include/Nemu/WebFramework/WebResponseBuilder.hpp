/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_WEBRESPONSEBUILDER_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_WEBRESPONSEBUILDER_HPP_

#include "ViewContext.hpp"
#include "Views.hpp"
#include <Ishiko/HTTP.hpp>
#include <string>

namespace Nemu
{

/// An interface to create the response that will be sent back to the client.
class WebResponseBuilder
{
public:
    WebResponseBuilder();

    void setStatus(unsigned int status);
    void setDateHeader(const Ishiko::UTCTime& time);
    std::string& body();

    std::string toString() const;

    /// Renders a page using the default templating engine.
    /**
        @param viewName The name of the view to render. How this name is used to find the right template depends on the
        engine and its options.
    */
    void view(const std::string& view, ViewContext& context);
    void view(const std::string& view, ViewContext& context, const std::string& layout);
    void view(const std::string& profile, const std::string& view, ViewContext& context);
    void view(const std::string& profile, const std::string& view, ViewContext& context, const std::string& layout);

    void redirect();

    void state();

private:
    Ishiko::HTTPResponse m_response;
    // TODO: I need to refactor HTTPResponse to make this more flexible and remove the redundant and wasteful m_body
    std::string m_body;
public:
    Views* m_views;
};

}

#endif

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_WEBREQUEST_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_WEBREQUEST_HPP_

#include <Ishiko/HTTP.hpp>
#include <Ishiko/Types.hpp>
#include <Nemu/Core.hpp>

namespace Nemu
{

/// An interface to the request that was received from the client
class WebRequest : public Ishiko::HTTPRequestPushParser::Callbacks
{
public:
    WebRequest();
    explicit WebRequest(Ishiko::URL url);

    /// Returns the requested URL.
    const Ishiko::URL& url() const;

    void onRequestURI(boost::string_view data) override;

private:
    Ishiko::URL m_url;
};

}

#endif

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_WEBREQUEST_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_WEBREQUEST_HPP_

#include <Ishiko/HTTP.hpp>
#include <Nemu/Core.hpp>

namespace Nemu
{

/// An interface to the request that was received from the client
class WebRequest : public Ishiko::HTTPMessagePushParser::Callbacks
{
public:
    /// Returns the URI part of the request.
    // TODO: can we avoid the copy here
    std::string URI() const;

    void onRequestURI(boost::string_view data) override;

private:
    std::string m_uri;
};

}

#endif

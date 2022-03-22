/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_ISHIKOCONNECTIONENGINE_ISHIKOWEBREQUEST_HPP_
#define _NEMU_CPP_ISHIKOCONNECTIONENGINE_ISHIKOWEBREQUEST_HPP_

#include <Ishiko/HTTP.hpp>
#include <Nemu/Core.hpp>

namespace Nemu
{

class IshikoWebRequest : public WebRequest, public Ishiko::HTTPMessagePushParser::Callbacks
{
public:
    std::string URI() const override;

    void onRequestURI(boost::string_view data) override;

private:
    std::string m_uri;
};

}

#endif

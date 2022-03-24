/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_ISHIKOCONNECTIONENGINE_ISHIKOWEBRESPONSEBUILDER_HPP_
#define _NEMU_CPP_ISHIKOCONNECTIONENGINE_ISHIKOWEBRESPONSEBUILDER_HPP_

#include <Ishiko/HTTP.hpp>
#include <Nemu/Core.hpp>
#include <string>

namespace Nemu
{

class IshikoWebResponseBuilder : public WebResponseBuilder
{
public:
    IshikoWebResponseBuilder(const Views& views);

    void setStatus(unsigned int status) override;
    void setDateHeader(Ishiko::TimePoint time) override;
    std::string& body() override;

    std::string toString() const;

private:
    Ishiko::HTTPResponse m_response;
    // TODO: I need to refactor HTTPResponse to make this more flexible and remove the redundant and wasteful m_body
    std::string m_body;
};

}

#endif

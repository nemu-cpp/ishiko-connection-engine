/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTWEBRESPONSEBUILDER_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_HELPERS_TESTWEBRESPONSEBUILDER_HPP_

#include "Nemu/WebFramework/WebResponseBuilder.hpp"
#include <Ishiko/Time.hpp>
#include <ostream>
#include <string>

// TODO: I don't need this class anymore since WebResponseBuilder is now not virtual anymore.
class TestWebResponseBuilder : public Nemu::WebResponseBuilder
{
public:
    TestWebResponseBuilder();

    unsigned int statusCode() const;

    void save(std::ostream& stream) const;

private:
    unsigned int m_statusCode;
    std::string m_body;
};

#endif

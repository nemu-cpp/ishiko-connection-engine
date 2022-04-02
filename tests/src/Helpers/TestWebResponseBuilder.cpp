/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "TestWebResponseBuilder.hpp"

using namespace Ishiko;
using namespace Nemu;
using namespace std;

TestWebResponseBuilder::TestWebResponseBuilder()
    : m_statusCode(0)
{
}

unsigned int TestWebResponseBuilder::statusCode() const
{
    return m_statusCode;
}

void TestWebResponseBuilder::save(ostream& stream) const
{
    stream << "Status Code: " << m_statusCode << "\r\n";
    stream << "Body:\r\n" << m_body;
}

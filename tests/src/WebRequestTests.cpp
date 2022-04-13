/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "WebRequestTests.hpp"
#include "Nemu/WebFramework/WebRequest.hpp"

using namespace Ishiko;
using namespace Nemu;

WebRequestTests::WebRequestTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "WebRequest tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void WebRequestTests::ConstructorTest1(Test& test)
{
    WebRequest request;

    ISHIKO_TEST_PASS();
}

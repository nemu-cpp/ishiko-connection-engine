/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "WebResponseBuilderTests.hpp"
#include "Nemu/Core.hpp"
#include "Nemu/WebFramework/WebResponseBuilder.hpp"

using namespace Ishiko;
using namespace Nemu;

WebResponseBuilderTests::WebResponseBuilderTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "WebResponseBuilder tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void WebResponseBuilderTests::ConstructorTest1(Test& test)
{
    WebResponseBuilder responseBuilder;

    ISHIKO_TEST_PASS();
}

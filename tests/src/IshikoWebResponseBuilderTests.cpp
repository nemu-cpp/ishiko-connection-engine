/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "IshikoWebResponseBuilderTests.hpp"
#include "Nemu/Core.hpp"
#include "Nemu/WebFramework/WebResponseBuilder.hpp"

using namespace Ishiko;
using namespace Nemu;

IshikoWebResponseBuilderTests::IshikoWebResponseBuilderTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "IshikoWebResponseBuilder tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void IshikoWebResponseBuilderTests::ConstructorTest1(Test& test)
{
    WebResponseBuilder responseBuilder;

    ISHIKO_TEST_PASS();
}

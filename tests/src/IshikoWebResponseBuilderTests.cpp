/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#include "IshikoWebResponseBuilderTests.hpp"
#include "Nemu/Core.hpp"
#include "Nemu/IshikoConnectionEngine/IshikoWebResponseBuilder.hpp"

using namespace Ishiko;
using namespace Nemu;

IshikoWebResponseBuilderTests::IshikoWebResponseBuilderTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "IshikoWebResponseBuilder tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void IshikoWebResponseBuilderTests::ConstructorTest1(Test& test)
{
    Views views;
    IshikoWebResponseBuilder responseBuilder(views);

    ISHIKO_TEST_PASS();
}

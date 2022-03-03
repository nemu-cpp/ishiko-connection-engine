/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#include "IshikoServerTests.hpp"
#include "Nemu/IshikoConnectionEngine/IshikoServer.hpp"

using namespace Ishiko::Tests;
using namespace Nemu;

IshikoServerTests::IshikoServerTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "IshikoServer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void IshikoServerTests::ConstructorTest1(Test& test)
{
    IshikoServer server;

    ISHIKO_PASS();
}

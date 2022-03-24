/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#include "IshikoWebResponseBuilderTests.hpp"

using namespace Ishiko;

IshikoWebResponseBuilderTests::IshikoWebResponseBuilderTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "IshikoWebResponseBuilder tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void IshikoWebResponseBuilderTests::ConstructorTest1(Test& test)
{
}

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#include "IshikoWebRequestTests.hpp"

using namespace Ishiko;

IshikoWebRequestTests::IshikoWebRequestTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "IshikoWebRequest tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void IshikoWebRequestTests::ConstructorTest1(Test& test)
{
}

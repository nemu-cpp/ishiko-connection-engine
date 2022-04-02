/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "IshikoWebRequestTests.hpp"
#include "Nemu/WebFramework/WebRequest.hpp"

using namespace Ishiko;
using namespace Nemu;

IshikoWebRequestTests::IshikoWebRequestTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "IshikoWebRequest tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void IshikoWebRequestTests::ConstructorTest1(Test& test)
{
    WebRequest request;

    ISHIKO_TEST_PASS();
}

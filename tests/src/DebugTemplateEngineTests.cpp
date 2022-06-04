/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "DebugTemplateEngineTests.hpp"

using namespace Ishiko;

DebugTemplateEngineTests::DebugTemplateEngineTests(const TestNumber& number,
    const TestContext& context)
    : TestSequence(number, "DebugTemplateEngine tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void DebugTemplateEngineTests::ConstructorTest1(Test& test)
{
}

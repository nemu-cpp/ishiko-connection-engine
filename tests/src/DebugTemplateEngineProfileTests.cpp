/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "DebugTemplateEngineProfileTests.hpp"

using namespace Ishiko;

DebugTemplateEngineProfileTests::DebugTemplateEngineProfileTests(const TestNumber& number,
    const TestContext& context)
    : TestSequence(number, "DebugTemplateEngineProfile tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void DebugTemplateEngineProfileTests::ConstructorTest1(Test& test)
{
}

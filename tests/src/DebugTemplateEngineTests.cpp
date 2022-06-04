/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "DebugTemplateEngineTests.hpp"
#include "Nemu/WebFramework/DebugTemplateEngine.hpp"

using namespace Ishiko;
using namespace Nemu;

DebugTemplateEngineTests::DebugTemplateEngineTests(const TestNumber& number,
    const TestContext& context)
    : TestSequence(number, "DebugTemplateEngine tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("createProfile test 1", CreateProfileTest1);
}

void DebugTemplateEngineTests::ConstructorTest1(Test& test)
{
    DebugTemplateEngine templateEngine;

    ISHIKO_TEST_PASS();
}

void DebugTemplateEngineTests::CreateProfileTest1(Test& test)
{
    DebugTemplateEngine templateEngine;

    Ishiko::Configuration configuration;
    std::shared_ptr<TemplateEngineProfile> templateEngineProfile = templateEngine.createProfile(configuration);

    ISHIKO_TEST_PASS();
}

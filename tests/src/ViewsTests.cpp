/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "ViewsTests.hpp"
#include "helpers/TestTemplateEngine.hpp"
#include "Nemu/WebFramework/Views.hpp"
#include <Ishiko/Configuration.hpp>
#include <memory>

using namespace Ishiko;
using namespace Nemu;

ViewsTests::ViewsTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Views tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("Constructor test 2", ConstructorTest2);
}

void ViewsTests::ConstructorTest1(Test& test)
{
    Views views;

    ISHIKO_TEST_PASS();
}

void ViewsTests::ConstructorTest2(Test& test)
{
    TestTemplateEngine engine;
    std::shared_ptr<TemplateEngineProfile> profile = engine.createProfile(Ishiko::Configuration());
    Views views(profile);

    ISHIKO_TEST_FAIL_IF_NEQ(&views.defaultProfile(), profile.get());
    ISHIKO_TEST_PASS();
}

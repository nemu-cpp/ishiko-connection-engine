/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "ViewsTests.hpp"
#include "helpers/TestTemplateEngine.hpp"
#include "helpers/TestTemplateEngineProfile.hpp"
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
    append<HeapAllocationErrorsTest>("set test 1", SetTest1);
    append<HeapAllocationErrorsTest>("set test 2", SetTest2);
    append<HeapAllocationErrorsTest>("set test 3", SetTest3);
}

void ViewsTests::ConstructorTest1(Test& test)
{
    Views views;

    ISHIKO_TEST_PASS();
}

void ViewsTests::ConstructorTest2(Test& test)
{
    TestTemplateEngine engine;
    Ishiko::Configuration configuration;
    configuration.set("text", "ViewsTests_ConstructorTest2");
    std::shared_ptr<TemplateEngineProfile> profile = engine.createProfile(configuration);
    Views views(profile);

    ISHIKO_TEST_FAIL_IF_NEQ(&views.defaultProfile(), profile.get());
    ISHIKO_TEST_PASS();
}

void ViewsTests::SetTest1(Test& test)
{
    Views views;

    TestTemplateEngine engine;
    Ishiko::Configuration configuration;
    configuration.set("text", "ViewsTests_SetTest1");
    std::shared_ptr<TemplateEngineProfile> profile = engine.createProfile(configuration);

    views.set("profile1", profile);

    ISHIKO_TEST_FAIL_IF_NEQ(&views.profile("profile1"), profile.get());
    ISHIKO_TEST_PASS();
}

void ViewsTests::SetTest2(Test& test)
{
    Views views;

    TestTemplateEngine engine;
    Ishiko::Configuration configuration1;
    configuration1.set("text", "ViewsTests_SetTest2_1");
    std::shared_ptr<TemplateEngineProfile> profile1 = engine.createProfile(configuration1);
    Ishiko::Configuration configuration2;
    configuration2.set("text", "ViewsTests_SetTest2_2");
    std::shared_ptr<TemplateEngineProfile> profile2 = engine.createProfile(configuration2);

    views.set("profile1", profile1);
    views.set("profile2", profile2);

    ISHIKO_TEST_FAIL_IF_NEQ(&views.profile("profile1"), profile1.get());
    ISHIKO_TEST_FAIL_IF_NEQ(&views.profile("profile2"), profile2.get());
    ISHIKO_TEST_PASS();
}

void ViewsTests::SetTest3(Test& test)
{
    Views views;

    TestTemplateEngine engine;
    Ishiko::Configuration configuration1;
    configuration1.set("text", "ViewsTests_SetTest2_1");
    std::shared_ptr<TemplateEngineProfile> profile1 = engine.createProfile(configuration1);
    Ishiko::Configuration configuration2;
    configuration2.set("text", "ViewsTests_SetTest2_2");
    std::shared_ptr<TemplateEngineProfile> profile2 = engine.createProfile(configuration2);

    views.set("profile", profile1);

    // Replace the previous profile
    views.set("profile", profile2);

    ISHIKO_TEST_FAIL_IF_NEQ(&views.profile("profile"), profile2.get());
    ISHIKO_TEST_PASS();
}

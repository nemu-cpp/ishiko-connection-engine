/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "WebResponseBuilderTests.hpp"
#include "helpers/TestTemplateEngine.hpp"
#include "helpers/TestTemplateEngineProfile.hpp"
#include "Nemu/Core.hpp"
#include "Nemu/WebFramework/MapViewContext.hpp"
#include "Nemu/WebFramework/Views.hpp"
#include "Nemu/WebFramework/WebResponseBuilder.hpp"
#include <Ishiko/Configuration.hpp>

using namespace Ishiko;
using namespace Nemu;

WebResponseBuilderTests::WebResponseBuilderTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "WebResponseBuilder tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("view test 1", ViewTest1);
    append<HeapAllocationErrorsTest>("view test 2", ViewTest2);
    append<HeapAllocationErrorsTest>("view test 3", ViewTest3);
}

void WebResponseBuilderTests::ConstructorTest1(Test& test)
{
    WebResponseBuilder responseBuilder;

    ISHIKO_TEST_PASS();
}

void WebResponseBuilderTests::ViewTest1(Test& test)
{
    WebResponseBuilder responseBuilder;

    TestTemplateEngine engine;
    Ishiko::Configuration configuration;
    configuration.set("text", "WebResponseBuilderTests_ViewTest1");
    Views views(engine.createProfile(configuration));
    responseBuilder.m_views = &views;

    MapViewContext context;
    context.map()["text"] = "ViewTest1";
    responseBuilder.view("index", context);

    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.body(),
        "<html><p>WebResponseBuilderTests_ViewTest1</p><p>ViewTest1</p></html>");
    ISHIKO_TEST_PASS();
}

void WebResponseBuilderTests::ViewTest2(Test& test)
{
    WebResponseBuilder responseBuilder;

    Views views;
    TestTemplateEngine engine;
    Ishiko::Configuration configuration;
    configuration.set("text", "WebResponseBuilderTests_ViewTest2");
    views.set("profile1", engine.createProfile(configuration));
    responseBuilder.m_views = &views;

    MapViewContext context;
    context.map()["text"] = "ViewTest2";
    responseBuilder.view("profile1", "index", context);

    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.body(), 
        "<html><p>WebResponseBuilderTests_ViewTest2</p><p>ViewTest2</p></html>");
    ISHIKO_TEST_PASS();
}

void WebResponseBuilderTests::ViewTest3(Test& test)
{
    WebResponseBuilder responseBuilder;

    Views views;
    TestTemplateEngine engine;
    Ishiko::Configuration configuration1;
    configuration1.set("text", "WebResponseBuilderTests_ViewTest3_1");
    views.set("profile1", engine.createProfile(configuration1));
    Ishiko::Configuration configuration2;
    configuration2.set("text", "WebResponseBuilderTests_ViewTest3_2");
    views.set("profile2", engine.createProfile(configuration2));
    responseBuilder.m_views = &views;

    MapViewContext context;
    context.map()["text"] = "ViewTest3";
    responseBuilder.view("profile1", "index", context);

    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.body(),
        "<html><p>WebResponseBuilderTests_ViewTest3_1</p><p>ViewTest3</p></html>");

    responseBuilder.view("profile2", "index", context);

    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.body(),
        "<html><p>WebResponseBuilderTests_ViewTest3_2</p><p>ViewTest3</p></html>");

    ISHIKO_TEST_PASS();
}

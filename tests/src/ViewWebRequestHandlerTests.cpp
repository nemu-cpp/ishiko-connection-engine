/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "ViewWebRequestHandlerTests.hpp"
#include "helpers/TestTemplateEngine.hpp"
#include "helpers/TestTemplateEngineProfile.hpp"
#include "Nemu/WebFramework/RequestHandlers/ViewWebRequestHandler.hpp"
#include <Ishiko/Configuration.hpp>

using namespace Ishiko;
using namespace Nemu;

ViewWebRequestHandlerTests::ViewWebRequestHandlerTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "ViewWebRequestHandler tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("run test 1", RunTest1);
    append<HeapAllocationErrorsTest>("run test 2", RunTest2);
    append<HeapAllocationErrorsTest>("run test 3", RunTest3);
    append<HeapAllocationErrorsTest>("run test 4", RunTest4);
}

void ViewWebRequestHandlerTests::ConstructorTest1(Test& test)
{
    ViewWebRequestHandler::PrefixMappingCallbacks callbacks("", "");
    ViewWebRequestHandler requestHandler(callbacks);

    ISHIKO_TEST_PASS();
}

void ViewWebRequestHandlerTests::RunTest1(Test& test)
{
    NullLoggingSink sink;
    Logger log(sink);

    TestTemplateEngine templateEngine;
    Ishiko::Configuration configuration;
    configuration.set("text", "ViewWebRequestHandlerTests_RunTest1");
    // We need to keep a pointer to the actual template engine profile because we want to run some tests on it.
    std::shared_ptr<TestTemplateEngineProfile> templateEngineProfile =
        std::static_pointer_cast<TestTemplateEngineProfile>(templateEngine.createProfile(configuration));
    Views views(templateEngineProfile);

    WebRequest request(URL("/"));
    WebResponseBuilder responseBuilder;
    responseBuilder.m_views = &views;

    ViewWebRequestHandler::PrefixMappingCallbacks callbacks("", "");
    ViewWebRequestHandler requestHandler(callbacks);
    requestHandler.context().map()["text"] = "RunTest1";
    requestHandler.run(request, responseBuilder, log);

    const std::vector<std::string> receivedViews = templateEngineProfile->receivedViews();
    const std::vector<std::string> receivedLayouts = templateEngineProfile->receivedLayouts();

    ISHIKO_TEST_ABORT_IF_NEQ(receivedViews.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(receivedViews[0], "/");
    ISHIKO_TEST_ABORT_IF_NEQ(receivedLayouts.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(receivedLayouts[0], "null");
    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.body(),
        "<html><p>ViewWebRequestHandlerTests_RunTest1</p><p>RunTest1</p></html>");
    ISHIKO_TEST_PASS();
}

void ViewWebRequestHandlerTests::RunTest2(Test& test)
{
    NullLoggingSink sink;
    Logger log(sink);

    TestTemplateEngine templateEngine;
    Ishiko::Configuration configuration;
    configuration.set("text", "ViewWebRequestHandlerTests_RunTest2");
    // We need to keep a pointer to the actual template engine profile because we want to run some tests on it.
    std::shared_ptr<TestTemplateEngineProfile> templateEngineProfile =
        std::static_pointer_cast<TestTemplateEngineProfile>(templateEngine.createProfile(configuration));
    Views views(templateEngineProfile);

    WebRequest request(URL("/"));
    WebResponseBuilder responseBuilder;
    responseBuilder.m_views = &views;

    ViewWebRequestHandler::PrefixMappingCallbacks callbacks("", "");
    ViewWebRequestHandler requestHandler(callbacks, "ViewWebRequestHandlerTests_RunTest2_layout.html");
    requestHandler.context().map()["text"] = "RunTest2";
    requestHandler.run(request, responseBuilder, log);

    const std::vector<std::string> receivedViews = templateEngineProfile->receivedViews();
    const std::vector<std::string> receivedLayouts = templateEngineProfile->receivedLayouts();

    ISHIKO_TEST_ABORT_IF_NEQ(receivedViews.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(receivedViews[0], "/");
    ISHIKO_TEST_ABORT_IF_NEQ(receivedLayouts.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(receivedLayouts[0], "ViewWebRequestHandlerTests_RunTest2_layout.html");
    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.body(),
        "<html><p>ViewWebRequestHandlerTests_RunTest2</p><p>RunTest2</p></html>");
    ISHIKO_TEST_PASS();
}

void ViewWebRequestHandlerTests::RunTest3(Test& test)
{
    NullLoggingSink sink;
    Logger log(sink);

    TestTemplateEngine templateEngine;
    Ishiko::Configuration configuration;
    configuration.set("text", "ViewWebRequestHandlerTests_RunTest3");
    // We need to keep a pointer to the actual template engine profile because we want to run some tests on it.
    std::shared_ptr<TestTemplateEngineProfile> templateEngineProfile =
        std::static_pointer_cast<TestTemplateEngineProfile>(templateEngine.createProfile(configuration));
    Views views(templateEngineProfile);

    WebRequest request(URL("/"));
    WebResponseBuilder responseBuilder;
    responseBuilder.m_views = &views;

    ViewWebRequestHandler::PrefixMappingCallbacks callbacks("", "pages");
    ViewWebRequestHandler requestHandler(callbacks);
    requestHandler.context().map()["text"] = "RunTest3";
    requestHandler.run(request, responseBuilder, log);

    const std::vector<std::string> receivedViews = templateEngineProfile->receivedViews();
    const std::vector<std::string> receivedLayouts = templateEngineProfile->receivedLayouts();

    ISHIKO_TEST_ABORT_IF_NEQ(receivedViews.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(receivedViews[0], "pages/");
    ISHIKO_TEST_ABORT_IF_NEQ(receivedLayouts.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(receivedLayouts[0], "null");
    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.body(),
        "<html><p>ViewWebRequestHandlerTests_RunTest3</p><p>RunTest3</p></html>");
    ISHIKO_TEST_PASS();
}

void ViewWebRequestHandlerTests::RunTest4(Test& test)
{
    NullLoggingSink sink;
    Logger log(sink);

    TestTemplateEngine templateEngine;
    Ishiko::Configuration configuration;
    configuration.set("text", "ViewWebRequestHandlerTests_RunTest4");
    // We need to keep a pointer to the actual template engine profile because we want to run some tests on it.
    std::shared_ptr<TestTemplateEngineProfile> templateEngineProfile =
        std::static_pointer_cast<TestTemplateEngineProfile>(templateEngine.createProfile(configuration));
    Views views(templateEngineProfile);

    WebRequest request(URL("mypages/page1.html"));
    WebResponseBuilder responseBuilder;
    responseBuilder.m_views = &views;

    ViewWebRequestHandler::PrefixMappingCallbacks callbacks("mypages", "pages");
    ViewWebRequestHandler requestHandler(callbacks);
    requestHandler.context().map()["text"] = "RunTest4";
    requestHandler.run(request, responseBuilder, log);

    const std::vector<std::string> receivedViews = templateEngineProfile->receivedViews();
    const std::vector<std::string> receivedLayouts = templateEngineProfile->receivedLayouts();

    ISHIKO_TEST_ABORT_IF_NEQ(receivedViews.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(receivedViews[0], "pages/page1.html");
    ISHIKO_TEST_ABORT_IF_NEQ(receivedLayouts.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(receivedLayouts[0], "null");
    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.body(),
        "<html><p>ViewWebRequestHandlerTests_RunTest4</p><p>RunTest4</p></html>");
    ISHIKO_TEST_PASS();
}

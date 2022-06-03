/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "ViewWebRequestHandlerTests.hpp"
#include "helpers/TestTemplateEngine.hpp"
#include "Nemu/WebFramework/RequestHandlers/ViewWebRequestHandler.hpp"
#include <Ishiko/Configuration.hpp>

using namespace Ishiko;
using namespace Nemu;

ViewWebRequestHandlerTests::ViewWebRequestHandlerTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "ViewWebRequestHandler tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("run test 1", RunTest1);
}

void ViewWebRequestHandlerTests::ConstructorTest1(Test& test)
{
    ViewWebRequestHandler::PrefixMappingCallbacks callbacks;
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
    Views views(templateEngine.createProfile(configuration));

    WebRequest request(URL("/"));
    WebResponseBuilder responseBuilder;
    responseBuilder.m_views = &views;

    ViewWebRequestHandler::PrefixMappingCallbacks callbacks;
    ViewWebRequestHandler requestHandler(callbacks);
    requestHandler.run(request, responseBuilder, log);

    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.body(), "<html>ViewWebRequestHandlerTests_RunTest1</html>");
    ISHIKO_TEST_PASS();
}

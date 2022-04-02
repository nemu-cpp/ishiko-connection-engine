/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "FunctionWebRequestHandlerTests.hpp"
#include "Helpers/TestWebRequest.hpp"
#include "Helpers/TestWebResponseBuilder.hpp"
#include "Nemu/WebFramework/RequestHandlers/FunctionWebRequestHandler.hpp"
#include <Ishiko/Logging.hpp>

using namespace Ishiko;
using namespace Nemu;

FunctionWebRequestHandlerTests::FunctionWebRequestHandlerTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "FunctionWebRequestHandler tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("run test 1", RunTest1);
}

void FunctionWebRequestHandlerTests::ConstructorTest1(Test& test)
{
    int data = 0;
    FunctionWebRequestHandler requestHandler(
        [data](const WebRequest& request, WebResponseBuilder& response, void* handlerData, Logger& logger)
        {
        });

    ISHIKO_TEST_PASS();
}

void FunctionWebRequestHandlerTests::RunTest1(Test& test)
{
    int data = 0;
    FunctionWebRequestHandler requestHandler(
        [&data](const WebRequest& request, WebResponseBuilder& response, void* handlerData, Logger& logger)
        {
            response.setStatus(200);
            response.body() = "body";
            data = 1;
        });

    TestWebRequest request("/");
    TestWebResponseBuilder responseBuilder;
    NullLoggingSink sink;
    Logger log(sink);

    requestHandler.run(request, responseBuilder, log);

    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.statusCode(), 200);
    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.body(), "body");
    ISHIKO_TEST_FAIL_IF_NEQ(data, 1);
    ISHIKO_TEST_PASS();
}

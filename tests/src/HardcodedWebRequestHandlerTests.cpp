/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "HardcodedWebRequestHandlerTests.hpp"
#include "Helpers/TestWebRequest.hpp"
#include "Helpers/TestWebResponseBuilder.hpp"
#include "Nemu/WebFramework/RequestHandlers/HardcodedWebRequestHandler.hpp"
#include <Ishiko/Logging.hpp>

using namespace boost::filesystem;
using namespace Ishiko;
using namespace Nemu;

HardcodedWebRequestHandlerTests::HardcodedWebRequestHandlerTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "HardcodedWebRequestHandler tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("run test 1", RunTest1);
}

void HardcodedWebRequestHandlerTests::ConstructorTest1(Test& test)
{
    HardcodedWebRequestHandler requestHandler(200, "");

    ISHIKO_TEST_PASS();
}

void HardcodedWebRequestHandlerTests::RunTest1(Test& test)
{
    HardcodedWebRequestHandler requestHandler(200, "body");

    TestWebRequest request("/");
    TestWebResponseBuilder responseBuilder;
    NullLoggingSink sink;
    Logger log(sink);

    requestHandler.run(request, responseBuilder, log);
    
    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.statusCode(), 200);
    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.body(), "body");
    ISHIKO_TEST_PASS();
}

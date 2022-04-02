/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "FunctionWebRequestHandlerTests.hpp"
#include "Nemu/WebFramework/RequestHandlers/FunctionWebRequestHandler.hpp"
#include <boost/filesystem.hpp>
#include <Ishiko/Logging.hpp>

using namespace boost::filesystem;
using namespace Ishiko;
using namespace Nemu;

FunctionWebRequestHandlerTests::FunctionWebRequestHandlerTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "FunctionWebRequestHandler tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<FileComparisonTest>("run test 1", RunTest1);
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

void FunctionWebRequestHandlerTests::RunTest1(FileComparisonTest& test)
{
    path outputPath(test.context().getTestOutputPath("FunctionWebRequestHandlerTests_RunTest1.bin"));
    path referencePath(test.context().getReferenceDataPath("FunctionWebRequestHandlerTests_RunTest1.bin"));

    int data = 0;
    FunctionWebRequestHandler requestHandler(
        [&data](const WebRequest& request, WebResponseBuilder& response, void* handlerData, Logger& logger)
        {
            response.setStatus(200);
            response.body() = "body";
            data = 1;
        });

    WebRequest request;
    WebResponseBuilder responseBuilder;
    NullLoggingSink sink;
    Logger log(sink);

    requestHandler.run(request, responseBuilder, log);

    ISHIKO_TEST_FAIL_IF_NEQ(data, 1);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(referencePath);

    ISHIKO_TEST_PASS();
}

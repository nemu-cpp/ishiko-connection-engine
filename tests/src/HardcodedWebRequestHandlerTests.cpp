/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "HardcodedWebRequestHandlerTests.hpp"
#include "Nemu/WebFramework/RequestHandlers/HardcodedWebRequestHandler.hpp"
#include <Ishiko/Logging.hpp>

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
    boost::filesystem::path outputPath = test.context().getOutputPath("HardcodedWebRequestHandlerTests_RunTest1.bin");
    std::ofstream stream(outputPath.c_str(), std::ios::binary);

    HardcodedWebRequestHandler requestHandler(200, "body");

    WebRequest request;
    WebResponseBuilder responseBuilder;
    NullLoggingSink sink;
    Logger log(sink);

    requestHandler.run(request, responseBuilder, log);
    
    stream << responseBuilder.toString();
    stream.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("HardcodedWebRequestHandlerTests_RunTest1.bin");
    ISHIKO_TEST_PASS();
}

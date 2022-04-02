/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "HardcodedWebRequestHandlerTests.hpp"
#include "Nemu/WebFramework/RequestHandlers/HardcodedWebRequestHandler.hpp"
#include <Ishiko/Logging.hpp>

using namespace boost::filesystem;
using namespace Ishiko;
using namespace Nemu;

HardcodedWebRequestHandlerTests::HardcodedWebRequestHandlerTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "HardcodedWebRequestHandler tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<FileComparisonTest>("run test 1", RunTest1);
}

void HardcodedWebRequestHandlerTests::ConstructorTest1(Test& test)
{
    HardcodedWebRequestHandler requestHandler(200, "");

    ISHIKO_TEST_PASS();
}

void HardcodedWebRequestHandlerTests::RunTest1(FileComparisonTest& test)
{
    path outputPath(test.context().getTestOutputPath("HardcodedWebRequestHandlerTests_RunTest1.bin"));
    std::ofstream stream(outputPath.c_str(), std::ios::binary);

    path referencePath(test.context().getReferenceDataPath("HardcodedWebRequestHandlerTests_RunTest1.bin"));

    HardcodedWebRequestHandler requestHandler(200, "body");

    WebRequest request;
    WebResponseBuilder responseBuilder;
    NullLoggingSink sink;
    Logger log(sink);

    requestHandler.run(request, responseBuilder, log);
    
    stream << responseBuilder.toString();

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(referencePath);

    ISHIKO_TEST_PASS();
}

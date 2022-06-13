/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "FileSystemWebRequestHandlerTests.hpp"
#include "Nemu/WebFramework/RequestHandlers/FileSystemWebRequestHandler.hpp"
#include <Ishiko/Logging.hpp>

using namespace Ishiko;
using namespace Nemu;

FileSystemWebRequestHandlerTests::FileSystemWebRequestHandlerTests(const TestNumber& number,
    const TestContext& context)
    : TestSequence(number, "FileSystemWebRequestHandler tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("run test 1", RunTest1);
    append<HeapAllocationErrorsTest>("run test 2", RunTest2);
    append<HeapAllocationErrorsTest>("run test 3", RunTest3);
    append<HeapAllocationErrorsTest>("run test 4", RunTest4);
    append<HeapAllocationErrorsTest>("run test 5", RunTest5);
    append<HeapAllocationErrorsTest>("run test 6", RunTest6);
}

void FileSystemWebRequestHandlerTests::ConstructorTest1(Test& test)
{
    FileSystemWebRequestHandler requestHandler(".");

    ISHIKO_TEST_PASS();
}

void FileSystemWebRequestHandlerTests::RunTest1(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("html");

    boost::filesystem::path outputPath = test.context().getOutputPath("FileSystemWebRequestHandlerTests_RunTest1.bin");
    std::ofstream stream(outputPath.c_str(), std::ios::binary);

    FileSystemWebRequestHandler requestHandler(inputPath.string().c_str());

    WebRequest request(URL(""));
    WebResponseBuilder responseBuilder;
    NullLoggingSink sink;
    Logger log(sink);

    requestHandler.run(request, responseBuilder, log);

    stream << responseBuilder.toString();
    stream.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("FileSystemWebRequestHandlerTests_RunTest1.bin");
    ISHIKO_TEST_PASS();
}

void FileSystemWebRequestHandlerTests::RunTest2(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("html");

    boost::filesystem::path outputPath = test.context().getOutputPath("FileSystemWebRequestHandlerTests_RunTest2.bin");
    std::ofstream stream(outputPath.c_str(), std::ios::binary);

    FileSystemWebRequestHandler requestHandler(inputPath.string().c_str());

    WebRequest request(URL("/"));
    WebResponseBuilder responseBuilder;
    NullLoggingSink sink;
    Logger log(sink);

    requestHandler.run(request, responseBuilder, log);

    stream << responseBuilder.toString();
    stream.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("FileSystemWebRequestHandlerTests_RunTest2.bin");
    ISHIKO_TEST_PASS();
}

void FileSystemWebRequestHandlerTests::RunTest3(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("html");

    boost::filesystem::path outputPath = test.context().getOutputPath("FileSystemWebRequestHandlerTests_RunTest3.bin");
    std::ofstream stream(outputPath.c_str(), std::ios::binary);

    FileSystemWebRequestHandler requestHandler(inputPath.string().c_str());

    WebRequest request(URL("/notfound"));
    WebResponseBuilder responseBuilder;
    NullLoggingSink sink;
    Logger log(sink);

    requestHandler.run(request, responseBuilder, log);

    stream << responseBuilder.toString();
    stream.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("FileSystemWebRequestHandlerTests_RunTest3.bin");
    ISHIKO_TEST_PASS();
}

void FileSystemWebRequestHandlerTests::RunTest4(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("html");

    boost::filesystem::path outputPath = test.context().getOutputPath("FileSystemWebRequestHandlerTests_RunTest4.bin");
    std::ofstream stream(outputPath.c_str(), std::ios::binary);

    FileSystemWebRequestHandler requestHandler(inputPath.string().c_str());

    WebRequest request(URL("file1.html"));
    WebResponseBuilder responseBuilder;
    NullLoggingSink sink;
    Logger log(sink);

    requestHandler.run(request, responseBuilder, log);

    stream << responseBuilder.toString();
    stream.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("FileSystemWebRequestHandlerTests_RunTest4.bin");
    ISHIKO_TEST_PASS();
}

void FileSystemWebRequestHandlerTests::RunTest5(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("html");

    boost::filesystem::path outputPath = test.context().getOutputPath("FileSystemWebRequestHandlerTests_RunTest5.bin");
    std::ofstream stream(outputPath.c_str(), std::ios::binary);

    FileSystemWebRequestHandler requestHandler(inputPath.string().c_str());

    WebRequest request(URL("dir1"));
    WebResponseBuilder responseBuilder;
    NullLoggingSink sink;
    Logger log(sink);

    requestHandler.run(request, responseBuilder, log);

    stream << responseBuilder.toString();
    stream.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("FileSystemWebRequestHandlerTests_RunTest5.bin");
    ISHIKO_TEST_PASS();
}

void FileSystemWebRequestHandlerTests::RunTest6(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("html");

    boost::filesystem::path outputPath = test.context().getOutputPath("FileSystemWebRequestHandlerTests_RunTest6.bin");
    std::ofstream stream(outputPath.c_str(), std::ios::binary);

    FileSystemWebRequestHandler requestHandler(inputPath.string().c_str());

    WebRequest request(URL("dir1/file2.html"));
    WebResponseBuilder responseBuilder;
    NullLoggingSink sink;
    Logger log(sink);

    requestHandler.run(request, responseBuilder, log);

    stream << responseBuilder.toString();
    stream.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("FileSystemWebRequestHandlerTests_RunTest6.bin");
    ISHIKO_TEST_PASS();
}

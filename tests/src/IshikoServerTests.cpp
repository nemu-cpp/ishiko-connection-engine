/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#include "IshikoServerTests.hpp"
#include "helpers/TestServerObserver.hpp"
#include "Nemu/IshikoConnectionEngine/IshikoServer.hpp"
#include <boost/filesystem.hpp>
#include <Ishiko/HTTP.hpp>
#include <Ishiko/Networking.hpp>

using namespace boost::filesystem;
using namespace Ishiko;
using namespace Ishiko::Tests;
using namespace Nemu;

IshikoServerTests::IshikoServerTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "IshikoServer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("start test 1", StartTest1);
    append<FileComparisonTest>("Request test 1", RequestTest1);
}

void IshikoServerTests::ConstructorTest1(Test& test)
{
    Error error;
    IshikoServer server(IPv4Address::Localhost(), 0, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_PASS();
}

void IshikoServerTests::StartTest1(Test& test)
{
    Error error;
    IshikoServer server(IPv4Address::Localhost(), 8585, error);

    ISHIKO_TEST_FAIL_IF(error);

    server.start();
    server.stop();
    server.join();

    ISHIKO_TEST_PASS();
}

void IshikoServerTests::RequestTest1(FileComparisonTest& test)
{
    path outputPath(test.context().getTestOutputPath("IshikoServerTests_RequestTest1.txt"));
    path referencePath(test.context().getReferenceDataPath("IshikoServerTests_RequestTest1.txt"));

    std::shared_ptr<TestServerObserver> observer = std::make_shared<TestServerObserver>();
    Error error;
    IshikoServer server(IPv4Address::Localhost(), 8586, error);

    server.start();

    std::ofstream responseFile(outputPath.string());
    HTTPClient::Get("127.0.0.1", 8088, "/", responseFile, error);
    responseFile.close();

    server.stop();
    server.join();

    const std::vector<std::tuple<TestServerObserver::EEventType, const Nemu::Server*, std::string>>& events =
        observer->connectionEvents();

    ISHIKO_TEST_ABORT_IF_NEQ(events.size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<0>(events[0]), TestServerObserver::eConnectionOpened);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<1>(events[0]), &server);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<2>(events[0]).substr(0, 10), "127.0.0.1:");
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<0>(events[1]), TestServerObserver::eConnectionClosed);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<1>(events[1]), &server);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<2>(events[0]), std::get<2>(events[1]));
    
    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(referencePath);

    ISHIKO_TEST_PASS();
}

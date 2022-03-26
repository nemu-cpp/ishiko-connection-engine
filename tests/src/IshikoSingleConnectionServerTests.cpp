/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#include "IshikoSingleConnectionServerTests.hpp"
#include "helpers/TestRoutes.hpp"
#include "helpers/TestServerObserver.hpp"
#include "Nemu/IshikoConnectionEngine/IshikoSingleConnectionServer.hpp"
#include <boost/filesystem.hpp>
#include <Ishiko/HTTP.hpp>
#include <Ishiko/Networking.hpp>

using namespace boost::filesystem;
using namespace Ishiko;
using namespace Nemu;

IshikoSingleConnectionServerTests::IshikoSingleConnectionServerTests(const TestNumber& number,
    const TestContext& context)
    : TestSequence(number, "IshikoSingleConnectionServer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("start test 1", StartTest1);
    append<FileComparisonTest>("Request test 1", RequestTest1);
}

void IshikoSingleConnectionServerTests::ConstructorTest1(Test& test)
{
    Error error;
    IshikoSingleConnectionServer server(IPv4Address::Localhost(), 0, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_PASS();
}

void IshikoSingleConnectionServerTests::StartTest1(Test& test)
{
    Error error;
    IshikoSingleConnectionServer server(IPv4Address::Localhost(), 8585, error);

    ISHIKO_TEST_FAIL_IF(error);

    server.start();
    server.stop();
    server.join();

    ISHIKO_TEST_PASS();
}

void IshikoSingleConnectionServerTests::RequestTest1(FileComparisonTest& test)
{
    path outputPath(test.context().getTestOutputPath("IshikoSingleConnectionServerTests_RequestTest1.bin"));
    path referencePath(test.context().getReferenceDataPath("IshikoSingleConnectionServerTests_RequestTest1.bin"));

    std::shared_ptr<TestServerObserver> observer = std::make_shared<TestServerObserver>();
    Error error;
    IshikoSingleConnectionServer server(IPv4Address::Localhost(), TCPServerSocket::AnyPort, error);

    TestRoutes routes;
    server.m_routes = &routes;

    server.start();

    std::ofstream responseFile(outputPath.string(), std::ios::out | std::ios::binary);
    HTTPClient::Get(IPv4Address::Localhost(), server.socket().port(), "/", responseFile, error);
    responseFile.close();

    server.stop();
    server.join();

    const std::vector<std::tuple<TestServerObserver::EEventType, const Nemu::Server*, std::string>>& events =
        observer->connectionEvents();

    /*
    * TODO
    ISHIKO_TEST_ABORT_IF_NEQ(events.size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<0>(events[0]), TestServerObserver::eConnectionOpened);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<1>(events[0]), &server);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<2>(events[0]).substr(0, 10), "127.0.0.1:");
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<0>(events[1]), TestServerObserver::eConnectionClosed);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<1>(events[1]), &server);
    ISHIKO_TEST_FAIL_IF_NEQ(std::get<2>(events[0]), std::get<2>(events[1]));
    */
    
    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(referencePath);

    ISHIKO_TEST_PASS();
}

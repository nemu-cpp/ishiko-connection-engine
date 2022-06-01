/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "RoutesTests.hpp"
#include "helpers/TestWebRequestHandler.hpp"
#include "Nemu/WebFramework/Routes.hpp"
#include <memory>
#include <vector>

using namespace Ishiko;
using namespace Nemu;

RoutesTests::RoutesTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Routes tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("add test 1", AddTest1);
    append<HeapAllocationErrorsTest>("add test 2", AddTest2);
    append<HeapAllocationErrorsTest>("add test 3", AddTest3);
    append<HeapAllocationErrorsTest>("match test 1", MatchTest1);
    append<HeapAllocationErrorsTest>("match test 2", MatchTest2);
    append<HeapAllocationErrorsTest>("match test 3", MatchTest3);
    append<HeapAllocationErrorsTest>("match test 4", MatchTest4);
    append<HeapAllocationErrorsTest>("match test 5", MatchTest5);
}

void RoutesTests::ConstructorTest1(Test& test)
{
    Routes routes;

    ISHIKO_TEST_ABORT_IF_NEQ(routes.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(routes.at(0).pathPattern(), "*");
    ISHIKO_TEST_PASS();
}

void RoutesTests::AddTest1(Test& test)
{
    Routes routes;
    std::shared_ptr<TestWebRequestHandler> handler = std::make_shared<TestWebRequestHandler>();
    routes.add(Route("/", handler));

    ISHIKO_TEST_ABORT_IF_NEQ(routes.size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(routes.at(0).pathPattern(), "/");
    ISHIKO_TEST_FAIL_IF_NEQ(&routes.at(0).requestHandler(), handler.get());
    ISHIKO_TEST_FAIL_IF_NEQ(routes.at(1).pathPattern(), "*");
    ISHIKO_TEST_PASS();
}

void RoutesTests::AddTest2(Test& test)
{
    Routes routes;

    std::vector<Route> moreRoutes;
    std::shared_ptr<TestWebRequestHandler> handler = std::make_shared<TestWebRequestHandler>();
    moreRoutes.emplace_back("/", handler);

    routes.add(moreRoutes);

    ISHIKO_TEST_ABORT_IF_NEQ(routes.size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(routes.at(0).pathPattern(), "/");
    ISHIKO_TEST_FAIL_IF_NEQ(&routes.at(0).requestHandler(), handler.get());
    ISHIKO_TEST_FAIL_IF_NEQ(routes.at(1).pathPattern(), "*");
    ISHIKO_TEST_PASS();
}

void RoutesTests::AddTest3(Test& test)
{
    Routes routes;

    std::vector<Route> moreRoutes;
    std::shared_ptr<TestWebRequestHandler> handler = std::make_shared<TestWebRequestHandler>();
    moreRoutes.emplace_back("/", handler);
    moreRoutes.emplace_back("/*", handler);

    routes.add(moreRoutes);

    ISHIKO_TEST_ABORT_IF_NEQ(routes.size(), 3);
    ISHIKO_TEST_FAIL_IF_NEQ(routes.at(0).pathPattern(), "/");
    ISHIKO_TEST_FAIL_IF_NEQ(&routes.at(0).requestHandler(), handler.get());
    ISHIKO_TEST_FAIL_IF_NEQ(routes.at(1).pathPattern(), "/*");
    ISHIKO_TEST_FAIL_IF_NEQ(&routes.at(1).requestHandler(), handler.get());
    ISHIKO_TEST_FAIL_IF_NEQ(routes.at(2).pathPattern(), "*");
    ISHIKO_TEST_PASS();
}

void RoutesTests::MatchTest1(Test& test)
{
    Routes routes;
    const Route& matchedRoute = routes.match("/");

    ISHIKO_TEST_FAIL_IF_NEQ(&matchedRoute, &routes.defaultRoute());
    ISHIKO_TEST_PASS();
}

void RoutesTests::MatchTest2(Test& test)
{
    Routes routes;
    std::shared_ptr<TestWebRequestHandler> handler = std::make_shared<TestWebRequestHandler>();
    routes.add(Route("/", handler));

    const Route& matchedRoute1 = routes.match("/");
    const Route& matchedRoute2 = routes.match("/index.html");

    ISHIKO_TEST_FAIL_IF_NEQ(&matchedRoute1.requestHandler(), handler.get());
    ISHIKO_TEST_FAIL_IF_NEQ(&matchedRoute2, &routes.defaultRoute());
    ISHIKO_TEST_PASS();
}

void RoutesTests::MatchTest3(Test& test)
{
    Routes routes;
    std::shared_ptr<TestWebRequestHandler> handler = std::make_shared<TestWebRequestHandler>();
    routes.add(Route("/*", handler));

    const Route& matchedRoute1 = routes.match("/");
    const Route& matchedRoute2 = routes.match("/index.html");

    ISHIKO_TEST_FAIL_IF_NEQ(&matchedRoute1.requestHandler(), handler.get());
    ISHIKO_TEST_FAIL_IF_NEQ(&matchedRoute2.requestHandler(), handler.get());
    ISHIKO_TEST_PASS();
}

void RoutesTests::MatchTest4(Test& test)
{
    Routes routes;
    std::shared_ptr<TestWebRequestHandler> prefixHandler = std::make_shared<TestWebRequestHandler>();
    routes.add(Route("/*", prefixHandler));
    std::shared_ptr<TestWebRequestHandler> exactHandler = std::make_shared<TestWebRequestHandler>();
    routes.add(Route("/", exactHandler));

    const Route& matchedRoute1 = routes.match("/");
    const Route& matchedRoute2 = routes.match("/index.html");

    ISHIKO_TEST_FAIL_IF_NEQ(&matchedRoute1.requestHandler(), exactHandler.get());
    ISHIKO_TEST_FAIL_IF_NEQ(&matchedRoute2.requestHandler(), prefixHandler.get());
    ISHIKO_TEST_PASS();
}

void RoutesTests::MatchTest5(Test& test)
{
    Routes routes;
    std::shared_ptr<TestWebRequestHandler> prefixHandler = std::make_shared<TestWebRequestHandler>();
    routes.add(Route("/subdir/*", prefixHandler));
    std::shared_ptr<TestWebRequestHandler> exactHandler = std::make_shared<TestWebRequestHandler>();
    routes.add(Route("/subdir/index.html", exactHandler));

    const Route& matchedRoute1 = routes.match("/");
    const Route& matchedRoute2 = routes.match("/subdir/file.html");
    const Route& matchedRoute3 = routes.match("/subdir/index.html");

    ISHIKO_TEST_FAIL_IF_NEQ(&matchedRoute1, &routes.defaultRoute());
    ISHIKO_TEST_FAIL_IF_NEQ(&matchedRoute2.requestHandler(), prefixHandler.get());
    ISHIKO_TEST_FAIL_IF_NEQ(&matchedRoute3.requestHandler(), exactHandler.get());
    ISHIKO_TEST_PASS();
}

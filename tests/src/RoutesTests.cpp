/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "RoutesTests.h"
#include "Helpers/TestWebRequestHandler.hpp"
#include "Nemu/WebFramework/Routes.hpp"

using namespace Ishiko;
using namespace Nemu;

RoutesTests::RoutesTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Routes tests", context)
{
    append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
    append<HeapAllocationErrorsTest>("match test 1", MatchTest1);
    append<HeapAllocationErrorsTest>("match test 2", MatchTest2);
}

void RoutesTests::CreationTest1(Test& test)
{
    Routes routes;

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
    routes.append(Route("/", handler));

    const Route& matchedRoute1 = routes.match("/");
    const Route& matchedRoute2 = routes.match("/index.html");

    ISHIKO_TEST_FAIL_IF_NEQ(&matchedRoute1.requestHandler(), handler.get());
    ISHIKO_TEST_FAIL_IF_NEQ(&matchedRoute2, &routes.defaultRoute());
    ISHIKO_TEST_PASS();
}

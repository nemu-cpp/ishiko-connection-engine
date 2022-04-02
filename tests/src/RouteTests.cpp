/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "RouteTests.h"
#include "Nemu/WebFramework/Route.hpp"
#include "Nemu/WebFramework/RequestHandlers/HardcodedWebRequestHandler.hpp"

using namespace Ishiko;
using namespace Nemu;
using namespace std;

RouteTests::RouteTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Route tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void RouteTests::ConstructorTest1(Test& test)
{
    Route route("/", make_shared<HardcodedWebRequestHandler>(200, "Hello World!"));

    ISHIKO_TEST_PASS();
}

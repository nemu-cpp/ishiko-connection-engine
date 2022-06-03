/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "MapViewContextTests.hpp"
#include "Nemu/WebFramework/MapViewContext.hpp"

using namespace Ishiko;
using namespace Nemu;

MapViewContextTests::MapViewContextTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "MapViewContext tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("getValue test 1", GetValueTest1);
}

void MapViewContextTests::ConstructorTest1(Test& test)
{
    MapViewContext viewContext;

    ISHIKO_TEST_PASS();
}

void MapViewContextTests::GetValueTest1(Ishiko::Test& test)
{
    MapViewContext viewContext;
    viewContext.map()["var1"] = "value1";

    Ishiko::Error error;
    std::string result;
    viewContext.getValue("var1", result, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(result, "value1");
    ISHIKO_TEST_PASS();
}

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
}

void MapViewContextTests::ConstructorTest1(Test& test)
{
    MapViewContext viewContext;

    ISHIKO_TEST_PASS();
}

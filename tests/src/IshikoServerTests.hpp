/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_ISHIKOCONNECTIONENGINE_TESTS_ISHIKOSERVERTESTS_H_
#define _NEMU_CPP_ISHIKOCONNECTIONENGINE_TESTS_ISHIKOSERVERTESTS_H_

#include <Ishiko/Tests.hpp>

class IshikoServerTests : public Ishiko::Tests::TestSequence
{
public:
    IshikoServerTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
    static void StartTest1(Ishiko::Tests::Test& test);
    static void RequestTest1(Ishiko::Tests::FileComparisonTest& test);
};

#endif

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_ISHIKOCONNECTIONENGINE_TESTS_ISHIKOSERVERTESTS_HPP_
#define _NEMU_CPP_ISHIKOCONNECTIONENGINE_TESTS_ISHIKOSERVERTESTS_HPP_

#include <Ishiko/Tests.hpp>

class IshikoServerTests : public Ishiko::TestSequence
{
public:
    IshikoServerTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void StartTest1(Ishiko::Test& test);
    static void RequestTest1(Ishiko::FileComparisonTest& test);
};

#endif

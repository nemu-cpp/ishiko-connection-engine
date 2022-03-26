/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_ISHIKOCONNECTIONENGINE_TESTS_ISHIKOSINGLECONNECTIONSERVERTESTS_HPP_
#define _NEMU_CPP_ISHIKOCONNECTIONENGINE_TESTS_ISHIKOSINGLECONNECTIONSERVERTESTS_HPP_

#include <Ishiko/Tests.hpp>

class IshikoSingleConnectionServerTests : public Ishiko::TestSequence
{
public:
    IshikoSingleConnectionServerTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void StartTest1(Ishiko::Test& test);
    static void RequestTest1(Ishiko::FileComparisonTest& test);
    static void RequestTest2(Ishiko::FileComparisonTest& test);
    static void RequestTest3(Ishiko::FileComparisonTest& test);
};

#endif

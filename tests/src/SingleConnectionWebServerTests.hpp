/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_SINGLECONNECTIONWEBSERVERTESTS_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_SINGLECONNECTIONWEBSERVERTESTS_HPP_

#include <Ishiko/TestFramework.hpp>

class SingleConnectionWebServerTests : public Ishiko::TestSequence
{
public:
    SingleConnectionWebServerTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void StartTest1(Ishiko::Test& test);
    static void RequestTest1(Ishiko::Test& test);
    static void RequestTest2(Ishiko::Test& test);
    static void RequestTest3(Ishiko::FileComparisonTest& test);
};

#endif

/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_ROUTESTESTS_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_ROUTESTESTS_HPP_

#include <Ishiko/TestFramework.hpp>

class RoutesTests : public Ishiko::TestSequence
{
public:
    RoutesTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void CreationTest1(Ishiko::Test& test);
    static void AddTest1(Ishiko::Test& test);
    static void AddTest2(Ishiko::Test& test);
    static void AddTest3(Ishiko::Test& test);
    static void MatchTest1(Ishiko::Test& test);
    static void MatchTest2(Ishiko::Test& test);
    static void MatchTest3(Ishiko::Test& test);
    static void MatchTest4(Ishiko::Test& test);
    static void MatchTest5(Ishiko::Test& test);
};

#endif

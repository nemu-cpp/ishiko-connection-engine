/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_ROUTESTESTS_H_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_ROUTESTESTS_H_

#include <Ishiko/Tests.hpp>

class RoutesTests : public Ishiko::TestSequence
{
public:
    RoutesTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void CreationTest1(Ishiko::Test& test);
    static void MatchTest1(Ishiko::Test& test);
};

#endif

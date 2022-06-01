/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_TESTS_WEBRESPONSEBUILDERTESTS_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_TESTS_WEBRESPONSEBUILDERTESTS_HPP_

#include <Ishiko/TestFramework.hpp>

class WebResponseBuilderTests : public Ishiko::TestSequence
{
public:
    WebResponseBuilderTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void ViewTest1(Ishiko::Test& test);
    static void ViewTest2(Ishiko::Test& test);
    static void ViewTest3(Ishiko::Test& test);
};

#endif

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_ISHIKOCONNECTIONENGINE_TESTS_ISHIKOWEBREQUESTTESTS_HPP_
#define _NEMU_CPP_ISHIKOCONNECTIONENGINE_TESTS_ISHIKOWEBREQUESTTESTS_HPP_

#include <Ishiko/Tests.hpp>

class IshikoWebRequestTests : public Ishiko::TestSequence
{
public:
    IshikoWebRequestTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
};

#endif

/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#include "IshikoServerTests.hpp"
#include "Nemu/IshikoConnectionEngine/linkoptions.hpp"
#include <Ishiko/Tests.hpp>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("NemuIshikoConnectionEngine");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<IshikoServerTests>();

    return theTestHarness.run();
}

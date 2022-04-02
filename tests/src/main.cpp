/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "IshikoSingleConnectionServerTests.hpp"
#include "IshikoWebRequestTests.hpp"
#include "IshikoWebResponseBuilderTests.hpp"
#include "Nemu/WebFramework/linkoptions.hpp"
#include <Ishiko/Tests.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("NemuIshikoConnectionEngine");

    theTestHarness.context().setTestOutputDirectory("../../output");
    theTestHarness.context().setReferenceDataDirectory("../../reference");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<IshikoSingleConnectionServerTests>();
    theTests.append<IshikoWebRequestTests>();
    theTests.append<IshikoWebResponseBuilderTests>();

    return theTestHarness.run();
}

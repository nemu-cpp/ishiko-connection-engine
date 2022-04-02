/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "IshikoWebRequestTests.hpp"
#include "IshikoWebResponseBuilderTests.hpp"
#include "FileSystemWebRequestHandlerTests.hpp"
#include "FunctionWebRequestHandlerTests.hpp"
#include "HardcodedWebRequestHandlerTests.hpp"
#include "RouteTests.h"
#include "RoutesTests.h"
#include "SingleConnectionWebServerTests.hpp"
#include "Nemu/WebFramework/linkoptions.hpp"
#include <Ishiko/Tests.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("NemuWebFramework");

    theTestHarness.context().setTestDataDirectory("../../data");
    theTestHarness.context().setTestOutputDirectory("../../output");
    theTestHarness.context().setReferenceDataDirectory("../../reference");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<SingleConnectionWebServerTests>();
    theTests.append<IshikoWebRequestTests>();
    theTests.append<IshikoWebResponseBuilderTests>();
    theTests.append<RouteTests>();
    theTests.append<RoutesTests>();
    theTests.append<HardcodedWebRequestHandlerTests>();
    theTests.append<FunctionWebRequestHandlerTests>();
    theTests.append<FileSystemWebRequestHandlerTests>();

    return theTestHarness.run();
}

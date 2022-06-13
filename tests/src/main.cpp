/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "DebugTemplateEngineProfileTests.hpp"
#include "DebugTemplateEngineTests.hpp"
#include "FileSystemWebRequestHandlerTests.hpp"
#include "FunctionWebRequestHandlerTests.hpp"
#include "HardcodedWebRequestHandlerTests.hpp"
#include "MapViewContextTests.hpp"
#include "RouteTests.hpp"
#include "RoutesTests.hpp"
#include "SingleConnectionWebServerTests.hpp"
#include "ViewsTests.hpp"
#include "ViewWebRequestHandlerTests.hpp"
#include "WebApplicationTests.hpp"
#include "WebRequestTests.hpp"
#include "WebResponseBuilderTests.hpp"
#include "Nemu/WebFramework/linkoptions.hpp"
#include <Ishiko/TestFramework.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("NemuWebFramework");

    theTestHarness.context().setDataDirectory("../../data");
    theTestHarness.context().setOutputDirectory("../../output");
    theTestHarness.context().setReferenceDirectory("../../reference");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<MapViewContextTests>();
    theTests.append<ViewsTests>();
    theTests.append<DebugTemplateEngineTests>();
    theTests.append<DebugTemplateEngineProfileTests>();
    theTests.append<SingleConnectionWebServerTests>();
    theTests.append<WebRequestTests>();
    theTests.append<WebResponseBuilderTests>();
    theTests.append<RouteTests>();
    theTests.append<RoutesTests>();
    theTests.append<HardcodedWebRequestHandlerTests>();
    theTests.append<FunctionWebRequestHandlerTests>();
    theTests.append<FileSystemWebRequestHandlerTests>();
    theTests.append<ViewWebRequestHandlerTests>();
    theTests.append<WebApplicationTests>();

    return theTestHarness.run();
}

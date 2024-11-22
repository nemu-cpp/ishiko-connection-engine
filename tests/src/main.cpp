// SPDX-FileCopyrightText: 2019-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

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
#include <exception>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    try
    {
        TestHarness::CommandLineSpecification command_line_spec;
        Configuration configuration = command_line_spec.createDefaultConfiguration();
        configuration.set("context.data", "../../data");
        configuration.set("context.output", "../../output");
        configuration.set("context.reference", "../../reference");
        CommandLineParser::parse(command_line_spec, argc, argv, configuration);

        TestHarness the_test_harness("NemuWebFramework Library Tests", configuration);

        TestSequence& the_tests = the_test_harness.tests();
        the_tests.append<MapViewContextTests>();
        the_tests.append<ViewsTests>();
        the_tests.append<DebugTemplateEngineTests>();
        the_tests.append<DebugTemplateEngineProfileTests>();
        the_tests.append<SingleConnectionWebServerTests>();
        the_tests.append<WebRequestTests>();
        the_tests.append<WebResponseBuilderTests>();
        the_tests.append<RouteTests>();
        the_tests.append<RoutesTests>();
        the_tests.append<HardcodedWebRequestHandlerTests>();
        the_tests.append<FunctionWebRequestHandlerTests>();
        the_tests.append<FileSystemWebRequestHandlerTests>();
        the_tests.append<ViewWebRequestHandlerTests>();
        the_tests.append<WebApplicationTests>();

        return the_test_harness.run();
    }
    catch (const std::exception& e)
    {
        return TestApplicationReturnCode::exception;
    }
    catch (...)
    {
        return TestApplicationReturnCode::exception;
    }
}

/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "WebApplicationTests.hpp"
#include "Nemu/WebFramework/SingleConnectionWebServer.hpp"
#include "Nemu/WebFramework/WebApplication.hpp"

using namespace Ishiko;
using namespace Nemu;

WebApplicationTests::WebApplicationTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "WebApplication tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void WebApplicationTests::ConstructorTest1(Test& test)
{
    std::shared_ptr<SingleConnectionWebServer> server =
        std::make_shared<SingleConnectionWebServer>(TCPServerSocket::AllInterfaces, Port::http);

    StreamLoggingSink sink(std::cout);
    Logger log(sink);

    WebApplication app(server, log);

    ISHIKO_TEST_PASS();
}

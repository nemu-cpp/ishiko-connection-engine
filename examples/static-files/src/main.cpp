/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/nemu/blob/main/LICENSE.txt
*/

#include <Nemu/WebFramework.hpp>
#include <Ishiko/Logging.hpp>
#include <Ishiko/Networking.hpp>
#include <exception>
#include <iostream>
#include <memory>

int main(int argc, char* argv[])
{
    // Create a log that sends its output to the console.
    // TODO: can I guarantee that this doesn't throw?
    Ishiko::StreamLoggingSink sink(std::cout);
    Ishiko::Logger logger(sink);

    try
    {
        // TODO: use the async server
        std::shared_ptr<Nemu::SingleConnectionWebServer> server =
            std::make_shared<Nemu::SingleConnectionWebServer>(Ishiko::TCPServerSocket::AllInterfaces,
                Ishiko::Port::http, logger);

        Nemu::WebApplication app(server, logger);

        // TODO: I should take this path relative to the executable location
        app.routes().add(Nemu::Route("/", std::make_shared<Nemu::FileSystemWebRequestHandler>("../../data")));

        app.run();

        return 0;
    }
    catch (const std::exception& e)
    {
        NEMU_LOG_ERROR("Exception thrown: {}", e.what());
        return -1;
    }
    catch (...)
    {
        NEMU_LOG_ERROR("Unknown exception thrown");
        return -1;
    }
}

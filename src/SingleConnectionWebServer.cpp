/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "SingleConnectionWebServer.hpp"
#include "WebRequest.hpp"
#include "WebResponseBuilder.hpp"
#include <Ishiko/HTTP.hpp>

namespace Nemu
{

SingleConnectionWebServer::SingleConnectionWebServer(Ishiko::IPv4Address address, Ishiko::Port port,
    Ishiko::Logger& logger)
    : m_logger(logger), m_socket(address, port), m_stop(false)
{
}

SingleConnectionWebServer::SingleConnectionWebServer(Ishiko::IPv4Address address, Ishiko::Port port,
    Ishiko::Logger& logger, Ishiko::Error& error) noexcept
    : m_logger(logger), m_init(error), m_socket(address, port, error), m_stop(false)
{
}

void SingleConnectionWebServer::start()
{
    // TODO: as a quick hack we put the blocking stuff in a secondary thread
    m_acceptThread = std::thread(
        [this]()
        {
            // TODO: this is a temporary blocking implementation
            // TODO: handle error
            while (!m_stop)
            {
                Ishiko::Error error;

                // TODO: logger is not threadsafe, need to sort this out
                Ishiko::Logger& logger = m_logger;

                NEMU_LOG_INFO("SingleConnectionWebServer server ready");

                Ishiko::TCPClientSocket clientSocket = m_socket.accept(error);

                WebRequest request;
                Ishiko::HTTPMessagePushParser requestParser(request);

                // TODO: how big should this buffer be? Adjust automatically?
                char buffer[1000];
                int n = clientSocket.read(buffer, 1000, error); // TODO: handle error
                while (!requestParser.onData(boost::string_view(buffer, n)) && (n != 0))
                {
                    n = clientSocket.read(buffer, 1000, error);
                }
                if (n == 0)
                {
                    // TODO: we received a partial request
                }
                else
                {                   
                    NEMU_LOG_INFO("Received request");

                    WebResponseBuilder response;
                    // TODO: cope with exceptions
                    m_requestHandler->run(request, response, m_logger);
                    std::string responseString = response.toString();
                    clientSocket.write(responseString.c_str(), responseString.size(), error);
                }
            }

            // Although the socket would be closed in the destructor, we need to close it here else client would still
            // be able to connect to it. They would hang because accept would never be called.
            // TODO: this means we can't stop and restart the server though
            m_socket.close();
        }
    );
}

void SingleConnectionWebServer::stop()
{
    m_stop = true;
    // TODO: for now send a dummy request to trigger the accept
    Ishiko::Error error;
    Ishiko::TCPClientSocket socket(error);
    if (m_socket.ipAddress() == 0)
    {
        socket.connect(Ishiko::IPv4Address::Localhost(), m_socket.port(), error);
    }
    else
    {
        socket.connect(m_socket.ipAddress(), m_socket.port(), error);
    }
}

void SingleConnectionWebServer::join()
{
    m_acceptThread.join();
}

bool SingleConnectionWebServer::isRunning() const
{
    // TODO
    return false;
}

const Ishiko::TCPServerSocket& SingleConnectionWebServer::socket() const
{
    return m_socket;
}

}

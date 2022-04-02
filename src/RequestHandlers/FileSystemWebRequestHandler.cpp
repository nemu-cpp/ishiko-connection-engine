/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "RequestHandlers/FileSystemWebRequestHandler.hpp"
#include <Ishiko/FileSystem.hpp>

using namespace boost::filesystem;
using namespace Ishiko;
using namespace std;

namespace Nemu
{

FileSystemWebRequestHandler::FileSystemWebRequestHandler(path root)
    : m_root(root)
{
    m_defaults.push_back("index.html");
}

void FileSystemWebRequestHandler::run(const WebRequest& request, WebResponseBuilder& response, Logger& logger)
{
    string uri = request.URI();
    if (uri == "/")
    {
        for (size_t i = 0; i < m_defaults.size(); ++i)
        {
            response.setStatus(200);
            // TODO: handle multiple default paths correctly
            path filePath = (m_root / m_defaults[i]);
            // TODO: handle error
            Error error;
            response.body() = FileSystem::ReadFile(filePath, error);
        }
    }
}

}

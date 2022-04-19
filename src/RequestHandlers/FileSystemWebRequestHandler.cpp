/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "RequestHandlers/FileSystemWebRequestHandler.hpp"
#include <Ishiko/FileSystem.hpp>

using namespace Ishiko;

namespace Nemu
{

FileSystemWebRequestHandler::FileSystemWebRequestHandler(boost::filesystem::path root)
    : m_root(root)
{
    m_defaults.push_back("index.html");
}

void FileSystemWebRequestHandler::run(const WebRequest& request, WebResponseBuilder& response, Logger& logger)
{
    std::string urlPath = request.url().path();
    if (urlPath.empty())
    {
        // TODO: I don't think this can actually happen if the URL comes from a web request
        urlPath = "/";
    }
    // TODO: does this guarantee we don't ignore the root?
    boost::filesystem::path filePath = (m_root / urlPath);
    Ishiko::Error error;
    // TODO: this behaviour should be configurable I guess, maybe this should only be done for "/"?
    if (Ishiko::FileSystem::IsDirectory(filePath.string().c_str(), error))
    {
        for (size_t i = 0; i < m_defaults.size(); ++i)
        {
            response.setStatus(200);
            // TODO: handle multiple default paths correctly
            boost::filesystem::path defaultFilePath = (filePath / m_defaults[i]);
            // TODO: handle error
            Error error;
            response.body() = FileSystem::ReadFile(defaultFilePath, error);
            return;
        }
    }
    if (!error)
    {
        // TODO: verifu this is a regular file? And no a link or something?
        response.setStatus(200);
        // TODO: handle error
        Error error;
        response.body() = FileSystem::ReadFile(filePath, error);
        return;
    }

    response.setStatus(404);
    response.body() = "The requested resource was not found";
}

}

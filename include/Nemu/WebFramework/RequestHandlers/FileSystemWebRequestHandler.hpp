/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_REQUESTHANDLERS_FILESYSTEMWEBREQUESTHANDLER_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_REQUESTHANDLERS_FILESYSTEMWEBREQUESTHANDLER_HPP_

#include "../WebRequestHandler.hpp"
#include <boost/filesystem.hpp>
#include <string>
#include <vector>

namespace Nemu
{

class FileSystemWebRequestHandler : public WebRequestHandler
{
public:
    FileSystemWebRequestHandler(boost::filesystem::path root);

    void run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger) override;

private:
    boost::filesystem::path m_root;
    std::vector<std::string> m_defaults;
};

}

#endif

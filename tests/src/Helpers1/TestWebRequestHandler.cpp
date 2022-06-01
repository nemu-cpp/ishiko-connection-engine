/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "TestWebRequestHandler.hpp"
#include <Ishiko/Time.hpp>

using namespace Ishiko;
using namespace Nemu;

void TestWebRequestHandler::run(const WebRequest& request, WebResponseBuilder& response, Logger& logger)
{
    response.setStatus(404);
    response.setDateHeader(UTCTime(Date(2022, 3, 24), TimeOfDay(1, 15, 0)));
}

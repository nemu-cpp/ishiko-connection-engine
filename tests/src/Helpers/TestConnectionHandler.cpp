/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#include "TestConnectionHandler.hpp"
#include <Ishiko/Time.hpp>

using namespace Ishiko;
using namespace Nemu;

void TestConnectionHandler::onConnection(const WebRequest& request, WebResponseBuilder& response)
{
    response.setDateHeader(UTCTime(Date(2022, 3, 24), TimeOfDay(1, 15, 0)));
    response.setStatus(404);
}

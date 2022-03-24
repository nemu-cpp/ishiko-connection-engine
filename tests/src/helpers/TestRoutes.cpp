/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#include "TestRoutes.hpp"
#include <Ishiko/Time.hpp>

using namespace Ishiko;
using namespace Nemu;

TestRoutes::TestRoutes()
{
    setDefaultRoute(Route("",
        [](const WebRequest& request, WebResponseBuilder& response, void* handlerData, Nemu::Logger& logger)
    {
        response.setDateHeader(TimePoint(Date(2022, 3, 24), TimeOfDay(1, 15, 0)));
        response.setStatus(404);
    }));
}

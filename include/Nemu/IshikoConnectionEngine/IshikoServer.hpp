/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_ISHIKOCONNECTIONENGINE_ISHIKOSERVER_H_
#define _NEMU_CPP_ISHIKOCONNECTIONENGINE_ISHIKOSERVER_H_

#include <Nemu/Core.h>

namespace Nemu
{

class IshikoServer : public Server
{
public:
    void start() override;
    void stop() override;
    void join() override;

    bool isRunning() const override;
};

}

#endif

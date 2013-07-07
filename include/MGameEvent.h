#ifndef __M_GAME_EVENT_H__
#define __M_GAME_EVENT_H__

#include <MEngine.h>
#include <MResource.h>
#include <MGame.h>

class MEventListener;

class MGameEvent : public MGame, public MResource
{
public:
    virtual void registerListener(MEventListener* listener) = 0;
    virtual void unregisterListener(MEventListener* listener) = 0;

public:
    virtual void sendEvent(const char* event) = 0;
};

// handy wrappers
#define MGameEventGet(inst)                              \
{                                                        \
    inst = (MGameEvent*)MResource::getNew("MGameEvent"); \
}

#define MEventSend(event)       \
{                               \
    MGameEvent* game = NULL;    \
    MGameEventGet(game);        \
    if(game)                    \
        game->sendEvent(event); \
}

#endif/*__M_GAME_EVENT_H__*/
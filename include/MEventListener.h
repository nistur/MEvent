#ifndef __M_EVENT_LISTENER_H__
#define __M_EVENT_LISTENER_H__

#include "MGameEvent.h"

class MEventListener
{
public:
    virtual void onEvent(const char* event) = 0;
};

#define MEventListenerDeclare(x)        \
x()                                     \
{                                       \
    MGameEvent* game = NULL;            \
    MGameEventGet(game);                \
    if(game)                            \
        game->registerListener(this);   \
}                                       \
~x()                                    \
{                                       \
    MGameEvent* game = NULL;            \
    MGameEventGet(game);                \
    if(game)                            \
        game->unregisterListener(this); \
}


#endif/*__M_EVENT_LISTENER_H__*/
#include "MEventListener.h"
#include "MGameEvent.h"

MEventListener::MEventListener()
{
    MGameEvent* game = NULL;
    MGameEventGet(game);
    if(game)
        game->registerListener(this);
}

MEventListener::~MEventListener()
{
    MGameEvent* game = NULL;
    MGameEventGet(game);
    if(game)
        game->unregisterListener(this);
}
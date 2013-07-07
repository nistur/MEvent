#include "MEventPlugin.h"
#include "MGameEventImpl.h"

MGame* s_prevGame = NULL;
extern MGameEventImpl* s_gameEventInstance;

MResource* getter()
{
    return MGameEventImpl::getInstance();
}

void MPluginStart(MEvent)
{
    MResource::registerFactory("MGameEvent", getter);

    MEngine* engine = MEngine::getInstance();
    s_prevGame = engine->getGame();
    s_gameEventInstance = new MGameEventImpl;
    engine->setGame(s_gameEventInstance);
}

void MPluginEnd(MEvent)
{
    MEngine* engine = MEngine::getInstance();
    engine->setGame(s_prevGame);
    s_gameEventInstance->destroy();
    s_prevGame = NULL;
    s_gameEventInstance = NULL;

    MResource::unregisterFactory("MGameEvent", getter);
}
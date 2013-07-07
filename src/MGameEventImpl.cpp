#include "MGameEventImpl.h"
#include "MEventListener.h"

void MGameEventImpl::registerListener(MEventListener* listener)
{
    m_listeners.push_back(listener);
}

void MGameEventImpl::unregisterListener(MEventListener* listener)
{
    listenerListIter iListener;
    for(iListener = m_listeners.begin();
        iListener != m_listeners.end();
        ++iListener)
        if(*iListener == listener)
            break;

    if(*iListener == listener)
        m_listeners.erase(iListener);
}

void MGameEventImpl::sendEvent(const char* event)
{
    for(listenerListIter iListener = m_listeners.begin();
        iListener != m_listeners.end();
        ++iListener)
        if(*iListener)
            (*iListener)->onEvent(event);
}

void MGameEventImpl::update()
{
    sendEvent("update");

    MGame::update();

    sendEvent("lateUpdate");
}

void MGameEventImpl::draw()
{
    sendEvent("preRender");

    MGame::draw();

    sendEvent("render");

    sendEvent("postRender");
}

void MGameEventImpl::destroy()
{
    delete this;
}

MGameEventImpl* s_gameEventInstance = NULL;
MGameEvent* MGameEventImpl::getInstance()
{
    return s_gameEventInstance;
}
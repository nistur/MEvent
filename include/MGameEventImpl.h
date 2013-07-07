#ifndef __M_GAME_EVENT_IMPL_H__
#define __M_GAME_EVENT_IMPL_H__

#include <vector>

#include "MGameEvent.h"

class MGameEventImpl : public MGameEvent
{
public:
    void registerListener(MEventListener* listener);
    void unregisterListener(MEventListener* listener);

public:
    void sendEvent(const char* event);

public:
    void update(void);
    void draw  (void);

public:
    void destroy();

    static MGameEvent* getInstance();

private:
    typedef std::vector<MEventListener*> listenerList;
    typedef listenerList::iterator       listenerListIter;
    listenerList                         m_listeners;
};

#endif/*__M_GAME_EVENT_H__*/
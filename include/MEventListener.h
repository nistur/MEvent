#ifndef __M_EVENT_LISTENER_H__
#define __M_EVENT_LISTENER_H__

class MEventListener
{
public:
    virtual void onEvent(const char* event) = 0;

public:
    MEventListener();
    ~MEventListener();
};

#endif/*__M_EVENT_LISTENER_H__*/
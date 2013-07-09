#ifndef __MEVENT_PLUGIN_H__
#define __MEVENT_PLUGIN_H__

#ifdef WIN32
# include <windows.h>
# ifdef M_EVENT_BUILD
#  define EXPORT __declspec(dllexport)
# else
#  define EXPORT __declspec(dllimport)
# endif
#else
# define EXPORT
#endif

#ifdef  M_EVENT_STATIC

#define MPluginStart(x) \
x##Start()

#define MPluginEnd(x)  \
x##End()

#else/*!M_EVENT_STATIC*/

#define MPluginStart(x) \
StartPlugin()

#define MPluginEnd(x)  \
EndPlugin()

#endif/*M_EVENT_STATIC*/

extern "C"
{

EXPORT void MPluginStart(MEvent);
EXPORT void MPluginEnd  (MEvent);

}
#endif/*__MEVENT_PLUGIN_H__*/
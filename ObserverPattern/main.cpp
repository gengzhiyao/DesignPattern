#include "EventManager.h"

int main ()
{
    ConcreteEvent concreteEvent (new EventManager);

    concreteEvent.m_eventManager->AddListener (new EmailListener);
    concreteEvent.m_eventManager->AddListener (new LoggingListener);

    concreteEvent.m_eventManager->Notify ();

    return 0;
}

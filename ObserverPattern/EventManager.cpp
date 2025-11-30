#include "EventManager.h"

void EventManager::AddListener (EventListener* listener)
{
    m_listeners.push_back (listener);
}

void EventManager::RemoveListener (EventListener* listener)
{
    m_listeners.remove (listener);
}

// 通知：遍历所有订阅的对象，依次调用
void EventManager::Notify ()
{
    for (auto element : m_listeners)
    {
        element->Update ();
    }
}

ConcreteEvent::ConcreteEvent (EventManager* eventManager)
    :m_eventManager (eventManager)
{
}
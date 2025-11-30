#pragma once
#include "Listener.h"
#include <list>

// 发布者会向其他对象发送值得关注的事件。发布者中包含一个允许订阅者加入和离开的订阅框架。
class EventManager
{
public:
    void AddListener (EventListener* listener);
    void RemoveListener (EventListener* listener);
    void Notify ();

private:
    std::list<EventListener*> m_listeners;  // 应用中可能有很多订阅者跟踪同一个发布者发布的事件
};


class ConcreteEvent
{
public:
    ConcreteEvent (EventManager* eventManager);


    EventManager* m_eventManager;
};
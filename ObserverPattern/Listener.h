#pragma once
#include <iostream>

// 观察者模式的核心在于建立对象的一对多的这种通知依赖关系
// 和策略模式不同，策略模式封装的是一系列算法行为的封装，可以用于在运行时动态替换
// 当观察者模式仅仅只有一个结构的情况下，两者的代码结构类似，但设计模式的概念体现在代码所要表达的意图上，而不是体现在代码结构上。

/* ---------------------------------------------------------------------------------------------- */
/*                                         所有具体订阅者必须实现相同的接口                            */
/* ---------------------------------------------------------------------------------------------- */

// 订阅者接口声明通知接口
class EventListener
{
public:
    virtual void Update () = 0;
};

class EmailListener :public EventListener
{
public:
    virtual void Update () override;
};

class LoggingListener :public EventListener
{
public:
    virtual void Update () override;
};
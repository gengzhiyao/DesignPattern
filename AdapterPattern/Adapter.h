
#include <iostream>

class Duck
{
public:
    virtual void quack() = 0;
    virtual void fly() = 0;
    virtual ~Duck() = default;
};

class MallardDuck : public Duck
{
public:
    virtual void quack() override;
    virtual void fly() override;
};

class Turkey
{
public:
    virtual void gobble() = 0;
    virtual void fly() = 0;
    virtual ~Turkey() = default;
};

class WildTurkey : public Turkey
{
public:
    virtual void gobble() override;
    virtual void fly() override;
};

class TurkeyAdapter : public Duck
{
public:
    TurkeyAdapter(Turkey *turkey);

    virtual void quack() override;
    virtual void fly() override;

public:
    //*所有的请求都委托给被适配者
    //*我缺鸭子，需要火鸡冒充
    Turkey *m_turkey;//不可使用非指针类型，抽象类不能实例化
};

// 通常会采用 public 继承目标接口 + private 继承被适配类
class MultiAdapter:public Duck,private WildTurkey{
    virtual void quack() override;
    virtual void fly() override;
};
#include <iostream>

class Strategy
{
public:
    virtual void execute();
};

class ConcreteStrategyAdd : public Strategy
{
public:
    void execute() override;
};

class ConcreteStrategySub : public Strategy
{
public:
    void execute() override;
};
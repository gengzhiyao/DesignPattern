#include <iostream>

class Strategy
{
public:
    virtual void execute();
};

class ConcreateStrategyAdd : public Strategy
{
public:
    void execute() override;
};

class ConcreateStrategySub : public Strategy
{
public:
    void execute() override;
};
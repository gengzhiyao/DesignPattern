#include "Strategy.h"

void Strategy::execute()
{
    std::cout << "Strategy::execute" << std::endl;
}

void ConcreteStrategyAdd::execute()
{
    std::cout << "ConcreteStrategyAdd::execute" << std::endl;
}

void ConcreteStrategySub::execute()
{
    std::cout << "ConcreteStrategySub::execute" << std::endl;
}

#include "Strategy.h"

void Strategy::execute()
{
    std::cout << "Strategy::execute" << std::endl;
}

void ConcreateStrategyAdd::execute()
{
    std::cout << "ConcreateStrategyAdd::execute" << std::endl;
}

void ConcreateStrategySub::execute()
{
    std::cout << "ConcreateStrategySub::execute" << std::endl;
}

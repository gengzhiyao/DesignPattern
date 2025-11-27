#include "Context.h"

void Context::setStrategy(Strategy *sty)
{
    strategy = sty;
}

void Context::executeStrategy()
{
    strategy->execute();
}
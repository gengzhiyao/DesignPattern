#include "Context.h"
#include <memory>

int main()
{
    Context context;
    std::unique_ptr<ConcreteStrategyAdd> styAdd = std::make_unique<ConcreteStrategyAdd>();
    context.setStrategy(styAdd.get());
    context.executeStrategy();
}
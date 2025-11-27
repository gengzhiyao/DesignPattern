#include "Context.h"
#include <memory>

int main()
{
    Context context;
    std::unique_ptr<ConcreateStrategyAdd> styAdd = std::make_unique<ConcreateStrategyAdd>();
    context.setStrategy(styAdd.get());
    context.executeStrategy();
}
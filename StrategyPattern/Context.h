#include "Strategy.h"

class Context{
public:
    void setStrategy(Strategy* sty);

    void executeStrategy();

private:
    Strategy* strategy;
};
#include "Adapter.h"
using std::cout, std::endl;

void MallardDuck::quack(){ cout << "Mallard quack()" << endl; }
void MallardDuck::fly() { cout << "Mallard fly()" << endl; }

void WildTurkey::gobble() { cout << "WildTurkey golbble()" << endl; }
void WildTurkey::fly() { cout << "WildTurkey fly()" << endl; }

TurkeyAdapter::TurkeyAdapter(Turkey *turkey):m_turkey(turkey){}//火鸡是被适配者接口

//*适配器实现目标接口，并持有适配者的实例
void TurkeyAdapter::quack() { m_turkey->gobble(); }
void TurkeyAdapter::fly() { m_turkey->fly(); }

void MultiAdapter::quack() {
    gobble();
}

void MultiAdapter::fly(){

}

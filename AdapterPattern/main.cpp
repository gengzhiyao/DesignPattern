#include "Adapter.h"

int main()
{
    WildTurkey *wildturkey = new WildTurkey();
    Duck *fake = new TurkeyAdapter(wildturkey);//用火鸡冒充鸭子，适配器实现鸭子接口，调用鸭子的方法，却输出了火鸡的方法
    //fake->quack();//客户通过目标接口调用适配器的方法对适配器发出请求，客户未察觉适配器起转换作用
    //fake->fly();

    Duck *d = new MultiAdapter();
    d->quack();
}

//客户和适配器是解耦的，一个不知道另一个
//**适配器模式将一个类的接口转换成客户期望的另一个接口。适配器让原本接口不兼容的类之间进行合作
//适配器模式、装饰器模式和外观模式是包装模式的三大具体应用
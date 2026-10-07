#include <iostream>

/**
 * Builder 和 Template Method 有异曲同工之处，都是固定函数调用流程，通过重写以控制执行过程中的具体执行步骤
 * 区别是：Template Method 中所固定的函数执行流程是编写在父类中，子类继承父类后 override 相应的虚函数，以更改所执行的固定步骤中的某一个细节；
 * 而 Builder 则是通过第三方固定好程序的执行流程，子类继承自父类 Builder 并重写响应的虚函数，以更改所执行的固定步骤，该第三方类就像一个领导：Director
 */

class Builder
{
public:
    virtual ~Builder( ) = default;
    virtual void Step1( ) = 0;
    virtual void Step2( ) = 0;
    virtual void Step3( ) = 0;
    virtual void Step4( ) = 0;
};

class ConcreteBuilder1 : public Builder
{
public:
    virtual void Step1( ) {}
    virtual void Step2( ) {}
    virtual void Step3( ) {}
    virtual void Step4( ) {}
};

class ConcreteBuilder2 : public Builder
{
public:
    virtual void Step1( ) {}
    virtual void Step2( ) {}
    virtual void Step3( ) {}
    virtual void Step4( ) {}
};

class Director
{
private:
    Builder* m_pBuilder;

public:
    Director( Builder* builder )
        : m_pBuilder( builder )
    {
    }

    void Process( )
    {
        m_pBuilder->Step1( );
        m_pBuilder->Step2( );
        m_pBuilder->Step3( );
        m_pBuilder->Step4( );
    }
};

int main( )
{
    Builder* pb1 = new ConcreteBuilder1;
    Director d( pb1 ); // 可以更换 ConcreteBuilder2 以更改细节
    d.Process( );

    return 0;
}
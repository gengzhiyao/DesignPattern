#include <iostream>

enum NetWorkState
{
    Open,
    Close,
    Connect
};

class Processor
{
private:
    NetWorkState state;

public:
    Processor( NetWorkState s )
        : state( s )
    {
    }
    void Operation1( );
    void Operation2( );
    void Operation3( );
};

void Processor::Operation1( )
{
    if ( state == Open )
    {
        // ...
        state = Close;
    }
    else if ( state == Connect )
    {
        // ***
        state = Open;
    }
    else
    {
        // ---
        state = Connect;
    }
}

class NetWorkStateObject
{
protected:
    NetWorkStateObject* m_pNext;

public:
    virtual ~NetWorkStateObject( ) = default;
    virtual void Operation1( ) = 0;
    virtual void Operation2( ) = 0;
    virtual void Operation3( ) = 0;

    void                SetNextState( NetWorkStateObject* nws ) { m_pNext = nws; }
    NetWorkStateObject* GetNextState( ) { return m_pNext; }
};

// Concrete State : 每个具体的状态中维护一个状态迁移方向
// 缺点：在新增状态时，需要修改入边对应的状态类，但不必修改出边对应的状态类
// 改善方式：维护一张状态迁移表
class CloseState : public NetWorkStateObject
{
public:
    virtual void Operation1( )
    {
        // ...
    }
    virtual void Operation2( )
    {
        // ***
    }
    virtual void Operation3( )
    {
        // ---
    }
};

class OpenState : public NetWorkStateObject
{
public:
    virtual void Operation1( )
    {
        // ...
        std::cout << "OpenState::Operation1( )" << std::endl;
        m_pNext->SetNextState( new CloseState );
    }
    virtual void Operation2( )
    {
        // ***
    }
    virtual void Operation3( )
    {
        // ---
    }
};

class ConnectState : public NetWorkStateObject
{
public:
    virtual void Operation1( )
    {
        // ...
    }
    virtual void Operation2( )
    {
        // ***
    }
    virtual void Operation3( )
    {
        // ---
    }
};

// Context : 持有当前状态指针
class ProcessorObject
{
private:
    NetWorkStateObject* m_state;

public:
    ProcessorObject( NetWorkStateObject* s )
        : m_state( s )
    {
    }

    void Operation1( )
    {
        m_state->Operation1( );
        m_state = m_state->GetNextState( );
    }
};

int main( )
{
    Processor p{ Open };
    p.Operation1( );

    ProcessorObject po( new OpenState );
    po.Operation1( );
    return 0;
}
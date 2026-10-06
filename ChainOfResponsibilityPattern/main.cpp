#include <iostream>

// 在 GUI 中，事件的命令路由，应用最为广泛，最为典型，教科书级别，尤其是在 MFC 的 WM_COMMAND 消息路由机制中
// 在现代编程中一般意识不到该模式的存在，因为目前使用链表这种数据结构已经非常成熟且非常流行了
// 而责任链模式的核心就是**将多个对象组成一张链表**，由具有能力处理命令的对象去处理

enum class Message
{
    Show = 1,
    Redraw,
    Click
};

class EvtHandler
{
protected:
    EvtHandler* m_pNextHandler;

public:
    EvtHandler( )
        : m_pNextHandler( nullptr )
    {
    }
    virtual bool CanProcess( const Message& msg ) = 0;
    virtual void Process( const Message& msg ) = 0;
    void         ForwardToNext( const Message& msg )
    {
        if ( m_pNextHandler ) m_pNextHandler->Process( msg );
    }
    void SetNextHandler( EvtHandler* handler ) { m_pNextHandler = handler; }
};

class Button : public EvtHandler
{
public:
    bool         CanProcess( const Message& msg ) override { return msg == Message::Click; }
    virtual void Process( const Message& msg ) override
    {
        if ( CanProcess( msg ) )
        {
            std::cout << "Process Button Click" << std::endl;
        }
        else
        {
            ForwardToNext( msg );
        }
    }
};

class Window : public EvtHandler
{
public:
    bool         CanProcess( const Message& msg ) override { return msg == Message::Show; }
    virtual void Process( const Message& msg ) override
    {
        if ( CanProcess( msg ) )
        {
            std::cout << "Process Window Show" << std::endl;
        }
        else
        {
            ForwardToNext( msg );
        }
    }
};

class Canvas : public EvtHandler
{
public:
    bool         CanProcess( const Message& msg ) override { return msg == Message::Redraw; }
    virtual void Process( const Message& msg ) override
    {
        if ( CanProcess( msg ) )
        {
            std::cout << "Process Canvas Redraw" << std::endl;
        }
        else
        {
            ForwardToNext( msg );
        }
    }
};

int main( int argc, char** argv )
{
    Window* pWnd = new Window;
    Canvas* pCvs = new Canvas;
    Button* pBtn = new Button;

    pBtn->SetNextHandler( pCvs );
    pCvs->SetNextHandler( pWnd );

    pBtn->Process( Message::Show );
    return 0;
}

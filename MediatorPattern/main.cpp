#include <iostream>
#include <typeinfo>
// 中介者：
// 两个或多个具体类之间不相互依赖，而是通过一个媒介类进行通信
// MFC 中的典型：MDI 主框架窗口、对话框。对话框作为中介，协调对话框内各个子控件之间交互；控件不直接互相调用，都交给父窗口（中介）处理通知
// 下面模拟将对话框作为中介者，实现点击按钮时，CheckBox 自动勾选复选框

class IMediator
{
public:
    virtual void Notify( ) = 0;
};

class Control
{
protected:
    IMediator* m_pMediator;

public:
    Control( IMediator* media )
        : m_pMediator( media )
    {
    }
};

class Button : public Control
{
public:
    Button( IMediator* media )
        : Control( media )
    {
    }
    void OnClick( ) { m_pMediator->Notify( ); }
};

class CheckBox : public Control
{
public:
    CheckBox( IMediator* media )
        : Control( media )
    {
    }
    void OnCheck( ) { std::cout << "CheckBox has been Checked..." << std::endl; }
};

class Dialog : public IMediator
{
public:
    Button*   m_pButton;
    CheckBox* m_pCheckBox;

public:
    Dialog( )
        : m_pButton( new Button( this ) ),
          m_pCheckBox( new CheckBox( this ) )
    {
    }
    void Notify( ) override;
};

void Dialog::Notify( )
{
    m_pCheckBox->OnCheck( );
}

int main( )
{
    Dialog dlg;
    dlg.m_pButton->OnClick( );
    return 0;
}
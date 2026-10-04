#include <iostream>

class Command
{
public:
    virtual ~Command( ) = default;
    virtual void execute( ) = 0;
};

class SampleCommand : public Command
{
public:
    void execute( ) { std::cout << "SampleCommand" << std::endl; }
};

class User
{
private:
    Command* m_onCommand;
    Command* m_offCommand;

public:
    void SetOnCommand( Command* cmd ) { m_onCommand = cmd; }
    void SetOffCommand( Command* Cmd ) { m_offCommand = Cmd; };

    void OnExecute( )
    {
        if ( m_onCommand ) m_onCommand->execute( );
    }
};

int main( )
{
    SampleCommand* samp = new SampleCommand;

    User* pUser = new User;
    pUser->SetOnCommand( samp );
    pUser->OnExecute( );
    return 0;
}

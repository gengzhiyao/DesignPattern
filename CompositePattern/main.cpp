#include <iostream>
#include <vector>

class Component
{
public:
    virtual ~Component( ) = default;
    virtual void AddComponent( Component* ) = 0;
    virtual void Process( ) = 0;
};

class Composite : public Component
{
protected:
    std::vector<Component*> m_components;

public:
    virtual void AddComponent( Component* comp ) { m_components.push_back( comp ); }
    virtual void Process( )
    {
        std::cout << "Composite" << std::endl;
        for ( auto& e : m_components )
        {
            e->Process( );
        }
    }
};

class Leaf : public Component
{
public:
    virtual void AddComponent( Component* comp ) { throw std::runtime_error( "Leaf can NOT Add component" ); }
    virtual void Process( ) { std::cout << "Leaf" << std::endl; }
};

int main( ) {
    Composite* operatorSystem = new Composite;
    Composite* Folder1 = new Composite;
    Composite* Folder2 = new Composite;
    Leaf*      File1 = new Leaf;
    Leaf*      File2 = new Leaf;
    Leaf*      File3 = new Leaf;

    operatorSystem->AddComponent( Folder1 );
    operatorSystem->AddComponent( Folder2 );
    Folder1->AddComponent( File1 );
    Folder1->AddComponent( File2 );
    Folder1->AddComponent( File3 );

    operatorSystem->Process( ); // C/C/L/L/L/C  OS/FOLD1/FILE1/FILE2/FILE3/FOLD2
    // Folder1->Process( );
    return 0;
}
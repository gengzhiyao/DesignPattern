#include <string>
#include <iostream>
#include "Iterator.h"

int main ()
{
    MyCollection<std::string> mc;

    mc.Add ("apple");
    mc.Add ("hello");
    mc.Add ("cherry");

    Iterator<std::string>* it = mc.GetIterator ();
    
    std::cout << "------遍历元素-------" << std::endl;
    for ( it->first();!it->isEnd(); it->next())
    {
        std::cout << it->current () << std::endl;
    }
    
}
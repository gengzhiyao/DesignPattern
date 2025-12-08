#include "Iterator.h"

void Alforithm ()
{
    MyCollection<int> mc;

    Iterator<int>* it = mc.GetIterator ();

    for (it->first (); !it->isEnd (); it->next ())
    {
        // 遍历操作
    }

}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"
#include "Set.h"

template <typename T>
ds::sn::Set<T> Intersection(const ds::sn::Set<T>& A,const ds::sn::Set<T>& B)
{
    return ds::sn::Set<T>();
}

template <typename T>
ds::sn::Set<T> Union(const ds::sn::Set<T>& A,const ds::sn::Set<T>& B)
{
    return ds::sn::Set<T>();
}

/********************************
 * Helper Functions : Begin
 *******************************/

//GenerateList() - creates a linked list of random decimal numbers
ds::sn::Set<int> GenerateSet(int n)
{
    int s = (n <= 0)?(10):(n);
    ds::sn::Set<int> S;

    while(S.Size() < s)
    {
        S.Insert((rand() % 1000 + 1));
    }
    return S;
} 

/********************************
 * Helper Functions : End
 *******************************/

int main()
{
    return 0; 
}

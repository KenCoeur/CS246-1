#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Set.h"
#include "Node.h"
#include "Iterator.h"

template <typename T>
bool Similar(ds::Node<T>* ptr1,ds::Node<T>* ptr2)
{
    return false;
}

bool DigitCount(int num1,int num2)
{
    return false;
}

/********************************
 * Helper Functions : Begin
 *******************************/

//Print() - prints elements of a linked list in a line
template <typename T>
void Print(ds::Node<T>* root)
{
    ds::sn::Iterator<T>* iter = new ds::sn::Iterator<T>(root);

    while(iter->HasNext())
    {
        std::cout << iter->Next() << " ";
    }
    std::cout << "\n"; 
    delete iter;
}

//PartialCopy() - creates a partial copy of a linked list
template <typename T>
ds::Node<T>* PartialCopy(ds::Node<T>* root,int n)
{
    if(root == NULL)
    {
        return NULL;
    }

    int cnt = (n <= 0)?(1):(n);
    ds::sn::Iterator<T>* iter = new ds::sn::Iterator<T>(root);
    ds::Node<T>* tmp = new ds::Node<T>(iter->Next());
    ds::Node<T>* tail = tmp;

    for(int i = 1;i < cnt && iter->HasNext();i += 1)
    {
        tail->SetLink(new ds::Node<T>(iter->Next()));
        tail = tail->GetLink();
    }
    delete iter;
    return tmp; 
}

//GenerateList() - creates a linked list of random decimal numbers
ds::Node<double>* GenerateList(int n)
{
    int s = (n <= 0)?(10):(n);
    ds::Node<double>* root = new ds::Node<double>(0);

    for(int i = 1;i < s;i += 1)
    {
        ds::Node<double>* tmp = new ds::Node<double>(0,root);
        root = tmp;
    }

    ds::sn::Iterator<double>* iter = new ds::sn::Iterator<double>(root);
    
    while(iter->HasNext())
    {
        iter->Next() = (rand() % 10000) / 100.0;
    }
    return root;
} 

//Swap() - swaps the data of two nodes of a linked list
template <typename T>
void Swap(ds::Node<T>* a,ds::Node<T>* b)
{
    T t = a->GetData();
    a->SetData(b->GetData()); //alternate: a->GetData() = b->GetData();
    b->SetData(t);
}

/********************************
 * Helper Functions : End
 *******************************/

int main()
{
    return 0; 
}

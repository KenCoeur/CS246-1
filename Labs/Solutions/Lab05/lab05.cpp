#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"

void RandInts(ds::Array<int>& arr,int lo,int hi)
{
    int mx = (hi >= lo)?(hi):(lo);
    int mn = (lo <= hi)?(lo):(hi);
    ds::it::Iterator<int>* iter = arr.ToIterator();

    while(iter->HasNext())
    {
        iter->Next() = rand() % (mx - mn + 1) + mn;
    }

    delete iter;
} 

void SortedInts(ds::Array<int>& arr,int start,bool dup)
{
    int prev = start;
    int c = (dup)?(0):(1);
    ds::it::Iterator<int>* iter = arr.ToIterator();

    while(iter->HasNext())
    {
        prev = prev + rand() % 10 + c;
        iter->Next() = prev; 
    }

    delete iter;
}

int MaxRepeats(ds::Array<int>& data)
{
    if(data.Size() == 0)
    {
        return 0;
    }

    int n = data.Size();
    ds::Array<int> values(n);
    int mcount = 0;
    int midx = 0;

    for(int i = 0;i < n;i += 1)
    {
        values[i] = 0;
    }

    for(int i = 1;i < n;i += 1)
    {
        values[data[i]] += 1;

        if(values[data[i]] > mcount)
        {
            mcount = values[data[i]];
            midx = data[i];
        }
        else if(values[data[i]] == mcount && data[i] < midx)
        {
            midx = data[i];
        }
        return midx;
    }
}

template <typename T>
int Intersection(ds::Array<T>& A,ds::Array<T>& B)
{

}

int Sums(ds::Array<int>& data,int target)
{
    int count = 0;
    int n = data.Size();

    
    for(int i = 0;i < n;i += 1)
    {
        for(int j = i + 1;j < n;j += 1)
        {
            if(data[i] + data[])
        }
    }
}
int main()
{
    srand(time(NULL));

    return 0; 
}

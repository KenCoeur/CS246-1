#include <iostream>
#include "Array.h"

bool TargetSum(ds::Array<int>& data,int target)
{
    int n = data.Size();

    for(int i = 0;i < n;i += 1)
    {
        for(int j = i + 1;j < n;j += 1)
        {
            if(data[i] + data[j] == target)
            {
                std::cout << "(" << i << "," << j << ")\n";
                return true; 
            }
        }
    }
    return false;
}

template <typename T>
int RemoveDuplicates(ds::Array<T>& data,const T& value)
{
    int n = data.Size();

    for(int i = 0;i < n;i += 1)
    {
        if(data[i] == value)
        {
            n -= 1;
            for(int j = i;j < n;j += 1)
            {
                data[j] = data[j+1];
            }
            i -= 1;
        }
    }
    return n;
}

template <typename T>
int SortedInsertIndex(ds::Array<T>& data,const T& target)
{
    int idx = 0;
    int n = data.Size();

    while(idx < n && data[idx] < target)
    {
        idx += 1;
    }
    return idx;
}

int main()
{
    return 0;
}
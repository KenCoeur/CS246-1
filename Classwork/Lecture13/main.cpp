#include <iostream>
#include <string>
#include "Pair.h"

int main()
{
    ds::Pair<std::string,int> a, b("First",1), c(b);

    a.SetKey("Zero");

    std::cout << a << "\n" << b << "\n" << c << "\n";

    if(b == c)
    {
        std::cout << "Yes\n\n";
    }
    return 0;
}
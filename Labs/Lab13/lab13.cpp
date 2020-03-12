#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Node.h"
#include "Stack.h"

void ReverseContent(std::ifstream& in,std::ofstream& out)
{
    return;
}

bool IsPattern(std::string str)
{
    return false;
}

int main()
{
    std::ofstream out("sample.txt");

    for(int i = 0;i < 3000;i += 1)
    {
        out << rand() % 10;

        if((i + 1) % 100 == 0)
        {
            out << "\n";
        }
    }

    out.close();
    return 0; 
}

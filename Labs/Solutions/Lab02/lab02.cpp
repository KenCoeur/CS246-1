#include <iostream>
#include "Circle.h"

int main()
{
    Circle circs[2] = {Circle(), Circle(5.25)};

    for(int i = 0;i < 2;i += 1)
    {
        std::cout << "Radius: " << circs[i] << "\n";
        std::cout << "Diameter: " << circs[i].Diameter() << "\n";
        std::cout << "Circumference: " << circs[i].Circumference() << "\n";
        std::cout << "Area: " << circs[i].Area() << "\n\n";
    }

    return 0;
}
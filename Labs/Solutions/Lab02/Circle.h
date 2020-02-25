#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <sstream>
#include <iomanip>

class Circle
{
private:
    double radius;
public:
    static const double PI;

    Circle() : Circle(1) {}

    Circle(double radius) : radius(radius) 
    {
        if(this->radius <= 0)
        {
            this->radius = 1;
        }
    }

    Circle(const Circle& obj)
    {
        radius = obj.radius;
    }

    Circle& operator=(const Circle& rhs)
    {
        if(this != &rhs)
        {
            radius = rhs.radius;
        }
        return *this;
    }

    ~Circle() {}

    double GetRadius() 
    {
        return radius;
    }

    double GetRadius() const 
    {
        return radius;
    }

    void SetRadius(double value)
    {
        if(value > 0)
        {
            radius = value;
        }
    }

    double Diameter() const 
    {
        return (2 * radius);
    }

    double Circumference() const
    {
        return (2 * radius * PI);
    }

    double Area() const 
    {
        return (radius * radius * PI);
    }

    std::string ToString() const 
    {
        std::stringstream out;

        out << std::fixed << std::setprecision(1) << radius;
        return out.str();
    }

    friend std::ostream& operator<<(std::ostream& out,const Circle& obj)
    {
        out << obj.ToString();
        return out;
    }
};

const double Circle::PI = 3.141592;

#endif
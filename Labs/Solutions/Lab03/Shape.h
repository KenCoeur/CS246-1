#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <sstream>

class Shape
{
public:
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Square : public Shape
{
private:
    double side;
public:
    Square() : side(1) {}

    Square(double side) : side(side)
    {
        if(this->side <= 0)
        {
            this->side = 1;
        }
    }

    Square(const Square& obj) : side(obj.side) {}

    Square& operator=(const Square& rhs)
    {
        if(this != &rhs)
        {
            side = rhs.side;
        }
        return *this;
    }

    ~Square() {}

    double GetSide() const 
    {
        return side;
    }

    void SetSide(double value)
    {
        if(value > 0)
        {
            side = value;
        }
    }

    double Perimeter() const 
    {
        return 4 * side;
    }

    double Area() const 
    {
        return side * side;
    }

    std::string ToString() const 
    {
        std::stringstream out;
        out << "(" << side << ")";
        return out.str();
    }

    friend std::ostream& operator<<(std::ostream& out,const Square& obj)
    {
        out << obj.ToString();
        return out;
    }
};

#endif
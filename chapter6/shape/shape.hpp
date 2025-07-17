#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>

class shape
{
private:
    /* data */
public:
    shape();
    virtual double area() const = 0 ;
    virtual double periemetr() const = 0;
    virtual void printInfo() const;
    virtual ~shape() = default;
};

#endif

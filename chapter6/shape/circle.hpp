#ifndef CIRCLE_HPP
#define CIRCLE_HPP


#include "shape.hpp"
class circle:public shape
{
    private:
        double radius;
    public:
        circle(double r);
        double area() const override;
        double periemetr() const override;

};



#endif 
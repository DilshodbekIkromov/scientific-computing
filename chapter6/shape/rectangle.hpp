#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"


class rectangle: public shape
{
private:
    double width;
    double height;
public:
    rectangle(double width, double height);
    double area() const override;
    double periemetr() const override;

};

#endif

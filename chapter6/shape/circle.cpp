#include "circle.hpp"
#include <iostream> 


circle::circle(double r) : radius(r){

}

double circle::area() const {
    const double pi = 3.14159265358979323846;
    return pi * radius * radius;
}

double circle::periemetr() const{
    const double pi = 3.14159265358979323846;
    return 2*pi*radius;

}


#include "rectangle.hpp"
#include <iostream>


rectangle::rectangle(double width, double height) : width(width), height(height) {

} 

double rectangle::area() const{
    return width*height;
}

double rectangle::periemetr() const {
    return 2*(width + height);
}

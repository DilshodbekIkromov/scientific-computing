#include "shape.hpp"

shape::shape()
{
    std::cout << "Shape object is created" << std::endl;

}

void shape::printInfo() const {

    std::cout << " Shape information: " << std::endl;
    std::cout << "This is shape area: " << area() << std::endl;
    std::cout << "This is periemetr of shape: " << periemetr() << std::endl;
    
}
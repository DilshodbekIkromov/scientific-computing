#include <iostream>

void printValue(int* a);

int main(){
    int a = 46;

    int* pA = &a;

    printValue(pA);
    return 0;
}

void printValue(int* a){
    std::cout << "This is the value " << *a << std::endl ;
}

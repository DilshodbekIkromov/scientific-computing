#include <iostream>

int main(){
    int  value   = 42;     // ordinary int
    int* pValue  = &value; // “pointer-to-int” holding value’s address

    std::cout << *pValue << '\n'; // 42  (dereference: go to the house and read)
    *pValue = 55;                 // modify through the pointer
    std::cout << pValue;

}
#include <iostream>
int main() {
    int  value  = 42;
    int* pValue = &value;      // store address of value

    std::cout << "Address : " << pValue  << '\n';
    std::cout << "Via ptr : " << *pValue << '\n';  // 42

    *pValue = 55;              // change original through pointer
    std::cout << "Now value = " << value << '\n';  // 55
}

#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    int* p_a = &a;
    int* p_b = &b;

    // Swap using a temporary variable through pointers
    int temp = *p_a;
    *p_a = *p_b;
    *p_b = temp;

    std::cout << "a = " << a << ", b = " << b << std::endl;
    return 0;
}
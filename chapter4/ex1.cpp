#include <iostream>

int main(){
    int i = 5;
    std::cout << i << "\n";

    int* p_j = &i;
    std::cout << i << "\n";

    *p_j = i*5;
    std::cout << i << "\n";

    int* p_k = new int(*p_j);
    std::cout << i << "\n";
    *p_j = 0;
    std::cout << i << "\n";
    std::cout << p_j << " This is p_j" << p_k << " This is p_k" << std::endl;
}





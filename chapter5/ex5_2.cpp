#include <iostream>

int changeInt(int* a);

int main(){
    int a = 45;
    int* pA = &a;
    changeInt(pA);
    std::cout << "this is the number " << a << std::endl;

}


int changeInt(int* a){
    *a = *a + 2;
    return *a;
}


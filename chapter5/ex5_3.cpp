#include <iostream> 

void pSwap(double* a, double* b);  
void rSwap(double &a, double &b);  

int main(){
    double a = 1.1;
    double b = 2.2;
    double* pA = &a;  
    double* pB = &b; 
    
    std::cout << "Before pSwap: a=" << a << ", b=" << b << std::endl;
    pSwap(pA, pB);
    std::cout << "After pSwap: a=" << a << ", b=" << b << std::endl;
    
    std::cout << "Before rSwap: a=" << a << ", b=" << b << std::endl;
    rSwap(a, b);
    std::cout << "After rSwap: a=" << a << ", b=" << b << std::endl;
    
    return 0;
}

void pSwap(double* a, double* b){
    double temp = *a;  
    *a = *b;
    *b = temp;
    std::cout << "pSwap completed" << std::endl;
}

void rSwap(double &a, double &b){
    double temp = a;   
    a = b;             
    b = temp;          
    std::cout << "rSwap completed" << std::endl;
}

// 
#include <iostream>
using namespace std;

int main(){
    double x,y,z;
    x = 10.0;
    y = -1.0;
    if ((x > y ) || (x < 5.0)){
        z = 4.0;
        cout << z << endl;
    }
    else {
        z=2.0;
        cout << z << endl;
    }

}

// 1. explain in words what the fragment of the code does ? 
// Answer: In the main function, x, y, and z are declared as double. 
// The code checks if x is greater than y OR x is less than 5.0. 
// If either condition is true, z is set to 4.0; otherwise, z is set to 2.0.

// 2. value of z when (a) x = 10.0, and y = -1.0;
// 4.0

// (b) x = 10.0, and y = 20.0;
// 2.0

// (c) x = 0.0, and y = 20.0.
// 4.0
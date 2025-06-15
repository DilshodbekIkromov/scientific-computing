#include <iostream>
#include <cmath> 

using namespace std;

int main(){
    double matrix1[2][2];
    double a, b; // Declare variables a and b
    
    cout << "Enter a: " << endl;
    cin >> a;
    matrix1[0][0] = a; // Assign to matrix after input
    
    cout << "Enter b: " << endl;
    cin >> b;
    matrix1[0][1] = b; // Assign to matrix after input
    
    matrix1[1][0] = a + b;
    matrix1[1][1] = a * b;
    
    // Display the matrix (optional)
    cout << "Matrix:" << endl;
    cout << matrix1[0][0] << " " << matrix1[0][1] << endl;
    cout << matrix1[1][0] << " " << matrix1[1][1] << endl;
    
    return 0; // Add return statement
}
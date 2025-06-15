#include <iostream> 
#include <cmath>

using namespace std; 

int main(){
    double vector1[13] = {2.0 , 5.0 , 40.0};
    double vector2[13] = {6.0 , 6.0, 80.0};

    // scalar product
    double scalar_product = 0.0;
    for (int i=0; i<3; i++){
        scalar_product += vector1[i]*vector2[i];
    }
    cout << "Scalar product is: " << scalar_product << "\n";

    // euclidian form
    double x = 0.0;
    for (int i=0; i<3; i++){
        x += vector1[i]*vector1[i];
    }
    cout << "Euclidian form of vector 1 is: " << x << "\n";
    
    double y = 0.0;
    for (int i=0;i<3;i++){
        y += vector2[i]*vector2[i];
    }
    cout << "Euclidian form of vector 2 is: " << y << "\n";

}

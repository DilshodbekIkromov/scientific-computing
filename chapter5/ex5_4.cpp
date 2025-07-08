#include <iostream>
#include <cmath>  

double stdv(double arr[], int size);

int main(){
    double sampleArray[10] = {1.0, 5.0, 6.2, 4.5, 8.3, 5.6, 9.9, 4.1, 6.5, 8.9};
    
    double standardDeviation = stdv(sampleArray, 10);  
    std::cout << "Standard deviation: " << standardDeviation << std::endl;
    
    return 0;
}

double stdv(double arr[], int size){
    double sum = 0.0;
    double mean = 0.0;
    double variance = 0.0;
    
    // Calculate mean
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    mean = sum / size;
    std::cout << "Mean: " << mean << std::endl;

    // Calculate variance
    for (int i = 0; i < size; i++){
        variance += (arr[i] - mean) * (arr[i] - mean) / (size - 1);
    }
    std::cout << "Variance: " << variance << std::endl;
    
    return sqrt(variance);
}




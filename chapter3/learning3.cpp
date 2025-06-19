#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;


//use when we know the exact number
// int main(){
//     double x[6], y[6];
//     ifstream read_file("Output.dat");
//     assert(read_file.is_open());
//     for (int i=0; i<6; i++){
//         read_file >> x[i] >> y[i];
//     }
//     read_file.close();
//     return 0;

// }

int main(){
    double x[100], y[100];
    ifstream read_file("Output.dat");
    assert(read_file.is_open());

    int i=0;
    while (!read_file.eof()){
        read_file >> x[i] >> y[i];
        i++;
    }
    read_file.close();
    return 0;
}

// additional 
// read_file.clear(); // Clears any error flags (e.g., EOF) so we can perform new operations on the file stream
// read_file.seekg(std::ios::beg); // Moves the file read position back to the beginning of the file

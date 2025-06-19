#include <cassert> // for using assert
#include <iostream>
#include <fstream> // for file input and output 
using namespace std;

int main(){
    double x[3] = {0.0, 1.0, 0.0};
    double y[3] = {0.0, 0.0, 1.0};
    // ofstream write_output("Output.dat"); // opens a file to write output
    std::ofstream write_output("Output.dat", std::ios::app);
    assert(write_output.is_open()); // ensures that the file is created successfully
    for (int i=0; i<3; i++){
        write_output << x[i] << " " << y[i] << "\n"; 
    }
    write_output.close(); 
// you can use .flush
// Forces any data still in the output buffer to be written to the file immediately.
// The file remains open and you can continue writing to it after flushing.
// Useful if you want to make sure data is saved to disk without closing the file.
// .close()
// Flushes the buffer (like .flush()), and then closes the file.
// After calling .close(), you cannot write to the file unless you reopen it.
    return 0;
}




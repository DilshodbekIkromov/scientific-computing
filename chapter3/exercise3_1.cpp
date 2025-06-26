#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;


int main(){
    double x[4] = {0.0, 1.0, 1.0, 0.0};
    double y[4] = {0.0, 0.0, 1.0, 1.0 };

    bool append_mode = true;
    ifstream check_file("x_and_y.dat");
    if (check_file.is_open()) {
        check_file.close();
        cout << "Warning: File 'x_and_y.dat' already exists.\n";
        cout << "Do you want to erase the existing file (o) or append to it (a)? [o/a]: ";
        char choice;
        cin >> choice;
        if (choice == 'o' || choice == 'O') {
            append_mode = false;
        }
    }

    ofstream write_output;
    if (append_mode) {
        write_output.open("x_and_y.dat", ios::app);
    } else {
        write_output.open("x_and_y.dat", ios::trunc);
    }
    assert(write_output.is_open());

    // Set precision, scientific notation, and show plus sign for positive numbers
    write_output.precision(10);
    write_output << scientific << showpos;

    for (int i=0; i<4; i++){
        write_output << x[i] << " ";
    }
    write_output << "\n";
    for (int i=0; i<4; i++){
        write_output << y[i] << " ";
    }
    write_output << "\n";
    write_output.close();

    return 0; 
}
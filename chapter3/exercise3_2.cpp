#include <iostream>
#include <fstream>

int main(){
    std::ifstream read_file("x_and_y.dat");
    if (!read_file.is_open())
    {
        std::cerr << "Error opening file.\n";
        return 1;
    }
    int number_of_rows = 0;
    double dummy1, dummy2;
    while (read_file >> dummy1 >> dummy2)
    {
        number_of_rows++;
    }
    std::cout << "Number of rows = " << number_of_rows << "\n";
    read_file.close();
    return 0;
}
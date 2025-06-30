// Example of using std::shared_ptr to manage memory safely

#include <memory>   // Lets you use smart pointers (C++11 or newer)
#include <iostream> // Lets you print to the screen

int main(){
    // Create a shared smart pointer to an integer
    std::shared_ptr<int> p_x(new int);

    // Print how many smart pointers are sharing the memory (should be 1)
    std::cout << "p_x use count: " << p_x.use_count() << "\n";

    // Store a value in the memory pointed to by p_x
    *p_x = 5;

    // Create another shared pointer that shares ownership of the same memory
    std::shared_ptr<int> p_y = p_x;

    // Now two smart pointers share the memory (should print 2)
    std::cout << "p_x use count: " << p_x.use_count() << "\n";

    // Reset p_y, so it no longer manages the memory
    p_y.reset();

    // Only p_x is left managing the memory (should print 1)
    std::cout << "p_x use count: " << p_x.use_count() << "\n";

    // Reset p_x, so no one manages the memory anymore (memory is freed)
    p_x.reset();

    // p_x is now empty (should print 0)
    std::cout << "p_x use count: " << p_x.use_count() << "\n";

    return 0;
}
#include <iostream>
#include <cassert>
#include <cstddef> 


template<typename T, std::size_t N>
class fixedvector
{
private:
    /* data */
    static_assert(N>0, "Fixed vector must be postive");
    T data[N];
public:
    // constexpr meaning it will be calculated at compile time. Ex: if you have fixedvactor<int, 5> compiler knows size() return 5
    // std::size_t special type for representing sizes and counts
    // const this fnction promises not to change the object 
    // noexcept means this function will never throw an error
    constexpr std::size_t size() const noexcept {return N;}
    // allows to read and write
    T& operator[](std::size_t i){
        assert(i < N && "Index out of bound");
        return data[i]
    }
    // overloading the function 
    // read only 
    const T& operator[](std::size_t i){
        assert(i < N && " Index out of bound");
        return data[i];
    }
//example 
// fixedvector<int, 3> myVector;        // Can be modified
// const fixedvector<int, 3> readOnly;  // Cannot be modified

// // Non-const version is called - you can read/write
// myVector[0] = 42;        // ✅ Works - can write
// int x = myVector[0];     // ✅ Works - can read

// // Const version is called - you can only read
// readOnly[0] = 42;        // ❌ Error! Cannot write
// int y = readOnly[0];     // ✅ Works - can read



};





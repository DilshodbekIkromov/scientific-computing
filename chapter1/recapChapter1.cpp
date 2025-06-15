// chapter1.cpp - Cheat Sheet for Chapter 1: Getting Started
// Based on "Guide to Scientific Computing in C++" by Joe Pitt-Francis and Jonathan Whiteley, Second Edition.

#include <iostream>  // Required for console input/output (std::cout, std::cin)
#include <cmath>     // Required for mathematical functions (sqrt, exp, pow, M_PI)
#include <cassert>   // Required for the assert statement
#include <string>    // Required for std::string type

// The main function is the entry point of every C++ program.
// The signature 'int main(int argc, char* argv[])' is used when command-line arguments are expected.
// For simplicity in basic programs, 'int main()' is often used.
int main()
{
    // --- 1.2 A First C++ Program: Hello World ---
    // The code within curly brackets {} contains instructions to execute.
    // 'std::cout' is used for console output. '\n' denotes a new line.
    // All C++ statements must end with a semi-colon ';'.
    std::cout << "Hello World\n";

    // Comments: Ignored by the compiler, essential for human readability and explaining code.
    /* This is a multi-line comment.
     * Anything between slash-asterisk and asterisk-slash is treated as a comment.
     * Comments are very useful to explain in English what the program does.
     */
    // This is a single-line comment. Anything after // to the end of the line is a comment.

    // Code indentation and whitespace are for readability and are ignored by the compiler.

    // --- 1.4 Variables ---
    // Variables must be declared with an appropriate type before they are used.

    // Basic Numerical Variables: 'int' for integers and 'double' for double precision floating point numbers.
    int integer_var;    // Declare an integer variable
    double double_var;  // Declare a double precision floating point variable

    // Assigning values to variables.
    integer_var = 10;
    double_var = 25.5;
    std::cout << "\n--- Variables ---\n";
    std::cout << "Integer variable: " << integer_var << "\n";
    std::cout << "Double variable: " << double_var << "\n";

    // Variables can be initialized at the time of declaration.
    int initialized_int = 100;
    double initialized_double = 123.456;
    std::cout << "Initialized integer: " << initialized_int << "\n";
    std::cout << "Initialized double: " << initialized_double << "\n";

    // Constant variables: The 'const' keyword ensures a variable's value cannot be changed after initialization.
    const double PI_VALUE = 3.1415926535; // Value from cmath is M_PI
    // PI_VALUE = 3.0; // This line would cause a compilation error as PI_VALUE is const.
    std::cout << "Constant PI_VALUE: " << PI_VALUE << "\n";

    // Mathematical Operations on Numerical Variables: Requires <cmath> for functions like sqrt, exp, pow.
    double x_val = 4.0, y_val = 2.0;
    double result;
    result = x_val / y_val;       // Division (result = 2.0)
    std::cout << "x_val / y_val: " << result << "\n";
    result = x_val * y_val;       // Multiplication (result = 8.0)
    std::cout << "x_val * y_val: " << result << "\n";
    result = sqrt(x_val);         // Square root (result = 2.0)
    std::cout << "sqrt(x_val): " << result << "\n";
    result = pow(x_val, y_val);   // x_val to the power of y_val (4.0^2.0 = 16.0)
    std::cout << "pow(x_val, y_val): " << result << "\n";

    // Shorthand Assignment Operators: Convenient for common operations.
    int counter = 5;
    counter += 3; // Equivalent to: counter = counter + 3; (counter is now 8)
    std::cout << "Counter after += 3: " << counter << "\n";
    counter *= 2; // Equivalent to: counter = counter * 2; (counter is now 16)
    std::cout << "Counter after *= 2: " << counter << "\n";
    counter++;    // Equivalent to: counter = counter + 1; (counter is now 17)
    std::cout << "Counter after ++: " << counter << "\n";
    counter--;    // Equivalent to: counter = counter - 1; (counter is now 16)
    std::cout << "Counter after --: " << counter << "\n";

    // Division of Integers: A common pitfall. Division of an integer by another integer returns only the integer part.
    int int_a = 7, int_b = 2;
    int int_div_result = int_a / int_b; // int_div_result will be 3 (not 3.5)
    std::cout << "Integer division (7 / 2): " << int_div_result << "\n";

    // Explicit Type Conversion (Casting): To get floating-point division, cast at least one operand to a floating-point type.
    double float_div_result = ((double)int_a) / int_b; // float_div_result will be 3.5
    std::cout << "Floating-point division (7.0 / 2.0) using cast: " << float_div_result << "\n";

    // Arrays: Store a fixed-size sequence of elements of the same type.
    // C++ uses ZERO-BASED INDEXING: the first element is at index 0, the last at index (size - 1).
    int my_array[3]; // Declares an integer array with 3 elements (indices 0, 1, 2)
    my_array[0] = 10;
    my_array[1] = 20;
    my_array[2] = 30;
    std::cout << "Array elements: " << my_array[0] << ", " << my_array[1] << ", " << my_array[2] << "\n";

    // Arrays can be initialized at declaration using curly braces.
    double coordinates[2] = {1.5, 2.8};
    std::cout << "Coordinates: (" << coordinates[0] << ", " << coordinates[1] << ")\n";

    // Multi-dimensional Arrays (Matrices): Declared with multiple sets of square brackets.
    int matrix[2][2] = {{1, 2}, {3, 4}}; // A 2x2 matrix
    std::cout << "Matrix element [0][0]: " << matrix[0][0] << ", [1][1]: " << matrix[1][1] << "\n";

    // ASCII Characters: 'char' type stores a single character. Single quotes are used.
    char grade = 'A';
    std::cout << "Student grade: " << grade << "\n";

    // Boolean Variables: 'bool' type stores 'true' (1) or 'false' (0).
    bool is_active = true;
    bool has_error = false;
    std::cout << "Is active: " << is_active << ", Has error: " << has_error << "\n";

    // Strings: 'std::string' type stores sequences of characters. Requires <string> header. Double quotes are used.
    std::string user_name = "Jane Doe";
    std::cout << "User name: " << user_name << "\n";
    std::cout << "Length of name: " << user_name.length() << "\n";        // Get string length
    std::cout << "First character: " << user_name.at(0) << "\n";          // Access character by index using at()
    std::cout << "Last character: " << user_name[user_name.length() - 1] << "\n"; // Access character by index using []
    // user_name.c_str() converts std::string to C-style string (char*).

    // --- 1.5 Simple Input and Output ---
    std::cout << "\n--- Input and Output ---\n";

    // Basic Console Output: 'std::cout' is typically sufficient for printing to screen.
    std::cout << "This is a line of text.\n";
    std::cout << "Multiple values can be printed: " << 123 << " " << 4.56 << " " << 'X' << "\n";

    // Common formatting commands:
    std::cout << "Newline: First line.\nSecond line.\n";     // \n (newline)
    std::cout << "Tab: Column1\tColumn2\n";                   // \t (tab)
    std::cout << "Literal quotes: \'Single\' and \"Double\"\n"; // \' and \" (literal single/double quote)

    // Flushing Output: 'std::cout.flush()' ensures buffered output is immediately written to the console.
    std::cout << "This message is flushed now.";
    std::cout.flush();
    std::cout << " This message appears immediately after the flush.\n";

    // Keyboard Input for Strings with Spaces: 'std::getline(std::cin, string_var)'
    // Reads an entire line from the keyboard, including spaces, until a newline is encountered.
    std::string full_address;
    std::cout << "Enter your full address (e.g., 123 Main St, Anytown): ";
    // Note: If a previous `std::cin >>` (for numbers) left a newline in the buffer,
    // `getline` might read it as an empty line. This example is placed to avoid that.
    std::getline(std::cin, full_address);
    std::cout << "Your address: " << full_address << "\n";

    // Keyboard Input for Numerical Variables: 'std::cin >> variable_name'
    // Reads input from the keyboard, typically space-separated values.
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age; // Reads an integer from the keyboard
    std::cout << "You entered age: " << age << "\n";

    double height;
    int siblings;
    std::cout << "Enter your height (e.g., 1.75) and number of siblings (e.g., 2): ";
    std::cin >> height >> siblings; // Can read multiple inputs
    std::cout << "Height: " << height << ", Siblings: " << siblings << "\n";

    // --- 1.6 The assert Statement ---
    std::cout << "\n--- Assert Statement ---\n";
    // 'assert(condition)' checks a condition. If the condition is false, the program terminates
    // and usually provides information about where the assertion failed.
    // This is useful for identifying unexpected occurrences during development.
    // Requires the <cassert> header.

    double value_for_sqrt;
    std::cout << "Enter a non-negative number to calculate its square root (e.g., 9.0): ";
    std::cin >> value_for_sqrt;
    assert(value_for_sqrt >= 0.0); // If value_for_sqrt is negative, this will terminate the program.
    std::cout << "The square root of " << value_for_sqrt << " is " << sqrt(value_for_sqrt) << "\n";

    // 'std::isfinite(x)' checks if x contains a finite value (not infinite or Not-a-Number).
    // double infinite_val = 1.0 / 0.0; // This creates an infinite value.
    // assert(std::isfinite(infinite_val)); // Uncommenting this would likely cause the program to assert.

    // Assertions can be automatically removed (deactivated) when compiling the code
    // with the -DNDEBUG flag (e.g., g++ -DNDEBUG chapter1.cpp).
    // This allows testing with assertions enabled, but deploying a faster program without them.

    // --- 1.7 Tips: Debugging Code (Conceptual notes, not runnable code) ---
    /*
    * Compile frequently: Save and compile often, especially with warning flags (-Wall, -Werror).
    * Save project frequently: Use version control systems (e.g., Git) to manage changes and revert if needed.
    * Test with simple examples: Manually verify results against simple cases.
    * Understand error messages: "Segmentation error" often indicates out-of-range array access or invalid memory use.
    * Use output for debugging: Print variable values at key points to trace program flow. Remember to flush output.
    * Use assertions: To check expected conditions at specific points in your code.
    * C++ arrays are zero-indexed: A common source of errors for beginners.
    * Use a debugger: For complex issues, a debugger (like GDB, often with a graphical front-end like ddd) allows step-by-step execution and variable inspection. Compile with the '-g' flag to include debugging information.
    */

    return 0; // Return 0 to indicate successful program execution.
}

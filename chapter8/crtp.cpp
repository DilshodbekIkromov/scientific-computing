// dynamic polymorphism uses virtual functions and a v-table (runtime cost)
// static polymorphism uses templates so that the compiler generates specialized code for each type
// CRTP is static polymorphism technique

// What you would do is write one base template that knows about its derived class 

// here is the analogy brroooo
// Manager (base class) template has generic task: process report 
// Specialist (derived class) knows exactly what kind of report to make 


// structure 
template<typename Derived>
class Base {
    // ...
};

class Derived : public Base<Derived> {
    // ...
};

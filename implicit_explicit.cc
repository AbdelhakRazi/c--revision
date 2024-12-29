#include <iostream>

class A {
    public:
        std::string name;
        int val;
        // a constructor with a single parameter, can perform implicitly type conversion.
        // a constructor with a single parameter, is a constructor + a type convertor.
        // if we want to tell compiler that it shouldn't be implicit type convertor, add explicit keyword.
        A (const std::string& name): name{name} {}
        operator std::string() const {return name;}; // type convertor from A to string
        operator int() const {return 5;};// type convertor from A to int
        void bark () const {
            std::cout << "barking" << std::endl;
        }
        // these type convertors should be avoided as possible, since it's making the interface hard to use, if someone mistakenly declare A as a string.
        // Avoid having two way implicit conversion
};

int main() {
    std::string name = "Abdelhak";
    A a = name; // implicit conversion from string to A, can't be used with pointers, because we simply need new operator to allocate memory
    // converting A to a string, using type conversion function
    std::string nm = a;
    std::cout << nm << std::endl;
    int val = a;
    std::cout << val << std::endl; 
    return 0;
}
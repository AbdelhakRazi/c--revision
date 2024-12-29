#include <iostream>

class A {
    public:
        std::string name;
        A (const std::string& name): name{name} {}
        void bark () const {
            std::cout << "barking" << std::endl;
        }
};
int main () {
    const char* test = "Hi world";
    char* tes2 = const_cast<char*>(test);
    //*tes2 = 'C'; this cannot be done bbecause it is a string literal, stored in read only memory, cannot be modified.
    std::cout << test << std::endl;
    test = "Salam"; // points to another value
    // what happened here ? actually the address of test is the same, because the address of test doesn't change
    // It is to where the variable test is stored
    // value of test is the, meaning if we derererence the pointer, it will point to the first character simply.

    std::cout << &test << std::endl;
    std::cout << tes2 << std::endl;
    // implicit type conversion
    return 0;
}
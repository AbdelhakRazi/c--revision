#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
// functor is a class that overrides the operator (), and defines the behaviour, when class is invoked like this A() for example
// defining a function like an object, gives more flexibility other than using function pointer, because in an object, it has state, variables..
// benefits: do more things than regular function
// we can have parameterized function, meaning defining attributes in class to parameteriz the function
class Addition {
    public:
       int operator() (int a, int b) {
        return a + b;
       }
       double operator() (int a) {
        return 2.0;
       }
};
class IsTwenty {
    public:
        bool operator() (int x){
            return x == 20;
        }
};

int main() {
    Addition add;
    int encScope = 2;
    std::cout << add(2, 3) << std::endl;
    std::cout << add(4) << std::endl;
    // STL defines ready to use functors
    int x = std::multiplies<int>() (3, 4);
    std::cout << x << std::endl;
    std::vector<int> vec{1, 2, 4, 20};
    std::vector<int>::const_iterator it = std::find_if(vec.cbegin(), vec.cend(), IsTwenty());
    if(it != vec.end()){
        std::cout << "Found value!: " << *it << std::endl;
    }
    // What is Lambda expression ? Lambda expression are inline, anonymous functions, to be put simply.
    // Often used when it's not going to be reused, short code, keep code clean and easy to read. Fast to execute
    // []: Capture clause, 
    // (): pass parameters
    // {} definition of lambda function
    // Example
    std::for_each(vec.begin(), vec.end(), [encScope](int& x) {
        x+=encScope; // override values in the vector
        std::cout << x + encScope << std::endl;
    });
    //[](){};
    // Power of lambda over function: has access to all variables in the enclosing scope!
    // To do that, we need to capture that variable through [encScope]
    // This will pass the variable by copy in non mutable lambda. If we need to modify them, we need to pass by reference
    std::for_each(vec.begin(), vec.end(), [&encScope](int& x) {
        encScope = x;
        std::cout << x + encScope << std::endl;
    });
    // passing mutliple variables,
    int e = 2;
    std::for_each(vec.begin(), vec.end(), [&encScope, e](int& x) {
        encScope = x;
        std::cout << x + encScope << std::endl;
        std::cout << e << std::endl;
    });
    // Pass all variables by reference, just do & alone [&]
    // Pass all variables by value, just do = [=]
    // [&, =var] : Capture everything by reference, except var by value
    // [=, &var]: Capture everythign by value, except var by reference
    // [this]: capture member variables and methods of an object
    // However [=] () mutable -> {}, mutable allows to modify the variable inside lambda
    // Original variable is not modified with mutable.
    return 0;
}
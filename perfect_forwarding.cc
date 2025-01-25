#include <iostream>




// in c++, the compiler deducts type automatically when u pass it
// Type deduction rules: interperation: if type is x and u apply y, u get z
// & & -> &
// & && -> &
// && & -> &&
// && && -> &&
// that's why when passing a type T&& in function argument, we should apply forward, that will remove reference from object, 
// std::forward implementation: remove_reference<x> and apply static_cast<T&&>

void receiver(int& x) { std::cout << "lvalue\n"; }
void receiver(int&& x) { std::cout << "rvalue\n"; }
// bad forwarding
template <typename T>
void bad_forward(T&& arg) {
    // problem: when an argument is bound to a named variable, it becomes automatically an lvalue
    // so here we'll always be passing an lvalue to the function
    receiver(arg);
}
template <typename T>
void good_forward(T&& arg) {
    // forward: T is deduced as T& if lvalue, or T&& if rvalue
    // when passing T to forward, it's not actually T, it's either T& or T&&.
    // this makes forward choose between overloads of T& and T&&, sicne there is no type reduction
    // that's why need overloads, both will remove reference, and acst to T&&
    // T& && -> T& and T&& && -> T&&
    // forward role: pass same category type of arg when it was passed, to calling functions
    receiver(std::forward<T>(arg));
}

int main() {
    std::cout << std::boolalpha; // enables printing true and false lol
    // std::remove_reference examples
    std::cout << "std::remove_reference<int>::type is int ? " << std::is_same<int, std::remove_reference<int>::type>::value << std::endl;
    std::cout << "std::remove_reference<int&>::type is int ? " << std::is_same<int, std::remove_reference<int&>::type>::value << std::endl;
    std::cout << "std::remove_reference<int>::type is int ? " << std::is_same<int, std::remove_reference<int&&>::type>::value << std::endl;
    std::cout << "std::remove_reference<const int&>::type is const int ? " << std::is_same<const int, std::remove_reference<const int&>::type>::value << std::endl;
    std::cout << "std::remove_reference<const int&&>::type is int ? " << std::is_same<const int, std::remove_reference<const int&&>::type>::value << std::endl;

    int a = 2;
    int& b = a;
    std::cout << "------------------- bad forwarding ---------------------" << std::endl;
    bad_forward(a); // false, considered like an lvalue int&
    bad_forward(b); // false
    bad_forward(2); // true, considered like an rvalue since it is literal for arg, but for T, it doesn't consider it with &&, so no worries.
    // good forward, with std::forward, we'll remove any reference from the arg, and apply &&. We get coherent results and true for all
    std::cout << "------------------- good forwarding ---------------------" << std::endl;
    good_forward(a); // true
    good_forward(b); // true
    good_forward(2); // true
    return 0;
}
#include <iostream>
#include <memory>
// make shared takes class arguments directly, preferred way of creating a shared pointer
// shared_ptr, takes a pointer instead towards the class.
class A {
    public:
    int a = 0;
    ~A(){
        std::cout << "Destroyed" << std::endl;
    }
};

int main() {
    std::shared_ptr<A> smartA = std::shared_ptr<A>(new A);
    {
        std::shared_ptr<A> smartAb = smartA;
        std::cout << smartA.use_count() << std::endl; // returns ref count
        std::cout << smartAb.unique() << std::endl; // checks if it's the unique owner of this object
        std::shared_ptr<A> smartB = std::make_shared<A>();
    }
    std::cout << smartA->a << std::endl;
    std::cout << "After braces" << std::endl;
    // get, reset, swap, same use as unique ptr.
    std::cout << smartA.use_count() << std::endl; // returns ref count
    std::cout << smartA.unique() << std::endl; // checks if it's the unique owner of this object
    return 0;
}
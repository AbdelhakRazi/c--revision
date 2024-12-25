#include <iostream>
#include <memory>
// make unique takes class arguments directly, preferred way of creating a shared pointer
// unique_ptr, takes a pointer instead towards the class.
// unique pointer ownership is only one, cannot be copied, only moved
class A {
    public:
    int a = 0;
    ~A(){
        std::cout << "Destroyed" << std::endl;
    }
};

int main() {
    std::unique_ptr<A> uniqueA = std::unique_ptr<A>(new A);
    std::cout << uniqueA->a << std::endl;
    std::cout << uniqueA.get() << std::endl;
    std::cout << "Transfering owernship" << std::endl;
    // tranfering ownership
    std::unique_ptr<A> uniqueAb = std::move(uniqueA);
    std::cout << uniqueAb.get() << std::endl; // get returns address of managed object, here the first new A
    A* rawA = uniqueAb.release(); // returns the managed object, and the object is no longer managed by uniqueAb
    std::cout << rawA << std::endl;
    // can use reset to delete the object, and takes optionally another one
    // swap, is to used ot swap to unique pointers.
    return 0;
}
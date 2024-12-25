#include <iostream>
#include <memory>
// unique pointer doesn't increase refs count, safe use to destroy objects when having circular dependecy
class B;
class A {
    public:
    int a = 4;
    std::weak_ptr<B> weakB;
    ~A() {
        std::cout << "A destroyed" << std::endl;
    }
};
class B {
    public:
    int a = 5;
    std::weak_ptr<A> weakA;
    ~B() {
        std::cout << "B destroyed" << std::endl;
    }
};

int main () {
    std::shared_ptr<A> smartA = std::make_shared<A>();
    std::shared_ptr<B> smartB = std::make_shared<B>();
    smartA->weakB = smartB;
    smartB->weakA = smartA;
    std::cout << "A refs count: " << smartA.use_count() << std::endl;
    std::cout << "B refs count: " << smartB.use_count() << std::endl;
    // provides safe access to pointers, thread safety as well, check if they're destroyed first
    std::cout << "Object has been destroyed ? :" << smartA->weakB.expired() << std::endl;
    if(auto shared = smartA->weakB.lock()){ // lock checks if it exists,a nd create a shared pointer
        std::cout << shared.use_count() << std::endl;
        std::cout << shared->a << std::endl;
    }
    //std::cout << smartA->weakB->a << std::endl; this goes against purpose of weak pointer
    return 0;
}
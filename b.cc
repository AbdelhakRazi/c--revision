#include "b.h"
#include <iostream>

void B::bark(){
    std::cout << "Hello world, I'm barking" << std::endl; 
}
B& operator*(B& lhs, B& rhs){
    return lhs;
}

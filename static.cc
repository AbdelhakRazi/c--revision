// a global variable can be used in another file by using extern.
// because a global variable is visible via external linking

// static variables has only internal linking, visible only in the file it is defined.
// same applies for defining functions, can't use same name
#include <iostream>
static int x = 0;
// static class members, can only be accessed via the class iself.
// we also ahve to initialize them outside of the class
// same for static class methods, part of the class, provides acces to static class members
// the reason why we can't access non static class members via static method, is because simply
// behind the scenes, methods of class has extra arguments which is self=this, that helps access class data members.
// static methods don't have this argument passed in.
// static declared inside funciton, has lifetime of entire program is running
// so if u call function again, the variable is already initialized
// available only on scope level.

// careful with classes! constepxr have to be static, because non static member variables are not known
// at compile time, since they are attached to an object!
int main() {
    std::cout << x << std::endl;
    return 0;
}
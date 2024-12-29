#ifndef __B__H__
#define __B__H__
class B {
    public:
        void bark();
};
B& operator*(const B& lhs, const B& rhs);
#endif  //!__B__H__
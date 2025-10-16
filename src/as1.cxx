#include "as1.hpp"
#include <iostream>

namespace homework {

void swap_ptr(int* a, int* b, int *c) { 
    int aOriginal = *a;
    *a = *b; //asked chat gpt what was wrong here because it felt suspiciously simple
    *b = *c; 
    *c = aOriginal; //chat told me to make C point to the ORIGINAL value of A, not the new value of A
    return;
}

int main(){
    int a = 1;
    int b = 2;
    int c = 3;
    swap_ptr(&a, &b, &c);
    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';
    std::cout << "c = " << c << '\n';
}

}; // namespace homework

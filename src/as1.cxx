#include "as1.hpp"
#include <iostream>

namespace homework {

void swap_ptr(int* a, int* b, int *c) { 
    *a = *b;
    *b = *c;
    *c = *a;
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

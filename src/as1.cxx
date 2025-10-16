#include "as1.hpp"
#include <iostream>

namespace homework {

    //As 1.1
void swap_ptr(int* a, int* b, int *c) { 
    int aOriginal = *a;
    *a = *b; //asked chat gpt what was wrong here because it felt suspiciously simple
    *b = *c; 
    *c = aOriginal; //chat told me to make C point to the ORIGINAL value of A, not the new value of A
    return;
}
}; // namespace homework

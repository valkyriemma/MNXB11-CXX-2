/** Use this main to test exercises. See the example with 'as1.0' below. 
 *  You can add all the exercise tests inside the same main.
 *  Don't forget to add includes properly.
 * */

#include "include/as1.hpp"
#include <iostream>

using namespace homework;

void swap_ptr(int* a, int* b, int *c) { 
    int aOriginal = *a;
    *a = *b; //asked chat gpt what was wrong here because it felt suspiciously simple
    *b = *c; 
    *c = aOriginal; //chat told me to make C point to the ORIGINAL value of A, not the new value of A
    return;
}

int main(){
    //As 1.1 complete
    int a = 1;
    int b = 2;
    int c = 3;
    homework::swap_ptr(&a, &b, &c);
    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';
    std::cout << "c = " << c << '\n';

    //As 1.2 complete
    homework::UniqueData test(1);
    test.set(2); 
    std::cout << "the value on the heap is now: " << test.get() << '\n';
 
}


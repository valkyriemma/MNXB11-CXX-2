#include "as1.hpp"
#include <iostream>
#include <memory>

namespace homework {

    //As 1.1
void swap_ptr(int* a, int* b, int *c) { 
    int aOriginal = *a;
    *a = *b; //asked chat gpt what was wrong here because it felt suspiciously simple
    *b = *c; 
    *c = aOriginal; //chat told me to make C point to the ORIGINAL value of A, not the new value of A
    return;
}

    //As 1.2
UniqueData::UniqueData(int value) {
    // constructor
    data_ = std::make_unique<int>(value);
}

int UniqueData::get() const {
    // get value in heap
    // use pointer? because "value" isnt known here
    return *data_; 
}

void UniqueData::set(int value) {
    // set value in heap
    *data_ = value;
}

}; // namespace homework

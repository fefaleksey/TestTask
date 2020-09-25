#include <iostream>

#include "bitesprinter.h"


void PrintBinary(int number_dec) {
    auto bites_count = sizeof(number_dec) * 8;

    for (size_t i = bites_count; i > 0;) {
        i--;
        std::cout << ((((uint) number_dec & (1u << i)) >> i) & 1u);
    }

    std::cout << std::endl;
}
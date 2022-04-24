//
// Created by zhixuan on 4/16/22.
//
#include "../Inc/Speaker.h"
#include <vector>
#include <iostream>
int main() {
    auto integers = {1, 2, 3, 4, 5};
    if (sum_integers(integers) == 16) {
        return 0;
    } else {
        std::cerr << "the result is not correct" << std::endl;
        return 1;
    }
}
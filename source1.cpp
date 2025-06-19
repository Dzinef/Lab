#include "header1.h"

void EnterSize(int32_t& size) {
    std::cout << "Enter size of array\n";
    std::cin >> size;
}

bool CheckSize(int32_t& size) {
    return size <= 100 && size > 0 ? true : false;
}

void EnterNumber(int32_t& number) {
    std::cin >> number;
}

bool CheckChoice(int32_t& number) {
    return number == 1 || number == 0 ? true : false;
}

void ReversElements(int32_t& right, int32_t& left) {
    if (right < left)
        std::swap(right, left);
}

void InputElements(int32_t& right, int32_t& left) {
    std::cout << "Input right border: ";
    std::cin >> right;
    std::cout << "Input left border: ";
    std::cin >> left;
    ReversElements(right, left);
}
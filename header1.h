#include <cmath>
#include <iostream>
#include <algorithm>

void EnterSize(int32_t&);
bool CheckSize(int32_t&);
void EnterNumber(int32_t&);
bool CheckChoice(int32_t&);
void ReversElements(int32_t&, int32_t&);
void InputElements(int32_t&, int32_t&);

template <typename T>
void InputArray(T* array, int32_t size) {
    std::cout << "Input " << size << " elements of the array:\n";
    for (int32_t i{}; i < size; ++i) {
        std::cout << "Element " << (i + 1) << ": ";
        std::cin >> array[i];
    }
}

template <typename T>
void OutputArray(T* arr, int32_t size) {
    for (int32_t i{}; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T SummOfArrayPos(T* arr, int32_t size) {
    T summ{};
    for (int32_t i{}; i < size; ++i) {
        if (arr[i] > 0)
            summ += arr[i];
    }
    return summ;
}

template<typename T>
T MaxElement(T* arr, int32_t size) {
    T maxElement{ arr[0] };
    int32_t maxIndex{};
    for (int32_t i = 0; i < size; ++i) {
        if (std::abs(arr[i]) > std::abs(maxElement)) {
            maxElement = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

template <typename T>
T MinElement(T* arr, int32_t size) {
    T minElement{ arr[0] };
    int32_t minIndex{};
    for (int32_t i = 0; i < size; ++i) {
        if (std::abs(arr[i]) <= std::abs(minElement)) {
            minElement = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

template <typename T>
T Multiplication(T* arr, int32_t size) {
    T minIndex{ MinElement(arr, size) }, maxIndex{ MaxElement(arr, size) };
    double multiplication{ 1.0 };
    for (int32_t i{}; i < size; ++i) {
        if (i < minIndex && i > maxIndex)
            multiplication *= arr[i];
    }
    if (multiplication == 1.0)
        return 0;
    return multiplication;
}

template <typename T>
void SortElements(T* arr, int32_t size) {
    for (int32_t i{ 1 }; i < size - 1; i += 2) {
        for (int32_t j{ i + 2 }; j < size; j += 2) {
            if (arr[i] < arr[j]) 
                std::swap(arr[i], arr[j]);
        }
    }
    OutputArray(arr, size);
}

template <typename T>
int32_t DifferentElements(T* arr, int32_t size) {
    int32_t counter{};
    for (int32_t i{}; i < size; ++i) {
        bool flag_find{ false };
        for (int32_t j{}; j < size; ++j) {
            if (i != j && arr[i] == arr[j]) {
                flag_find = true;
                break;
            }
        }
        if (!flag_find)
            ++counter;
    }
    return counter;
}

template <typename T>
T MultiplicationAfter(T* arr, int32_t size) {
    T maxIndex{ MaxElement(arr, size) };
    double multiplication{ 1.0 };
    for (int32_t i{}; i < size; ++i) {
        if (i > maxIndex)
            multiplication *= arr[i];
    }
    if (multiplication == 1.0)
        return 0;
    return multiplication;
}

template <typename T>
void SortArrayNegativse(T* arr, int32_t size) {
    int32_t left{ 0 }, right{ size - 1 };
    while (left <= right) {
        if (arr[left] < 0) {
            ++left; 
        }
        else if (arr[right] >= 0) {
            --right; 
        }
        else {
            std::swap(arr[left], arr[right]);
            ++left;
            --right;
        }
    }
    OutputArray(arr, size);
}

template <typename T>
void FillArray(T* arr, int32_t size, int32_t right, int32_t left) {
    std::srand(time(NULL));
    for (int32_t i{}; i < size; ++i) {
        arr[i] = rand() % right - left;
    }
}

template <typename T>
void DeleteArray(T* arr) {
    delete[] arr;
}
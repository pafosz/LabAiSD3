#pragma once
#include <random>
#include <iostream>


std::vector<int> generateRandomArray(int lower_bound, int upper_bound, size_t size) {
    std::random_device rd;  // Источник случайных чисел
    std::mt19937 gen(rd()); // Генератор случайных чисел
    std::uniform_int_distribution<int> distribution(lower_bound, upper_bound); // Равномерное распределение

    std::vector<int> randomArray;
    randomArray.reserve(size);

    for (size_t i = 0; i < size; ++i) {
        randomArray.push_back(distribution(gen)); // Генерация случайного числа и добавление в массив
    }

    return randomArray;
}

// Генератор отсортированного массива
std::vector<int> generateSortedArray(size_t size) {
    std::vector<int> sortedArray;
    for (size_t i = 1; i <= size; ++i) {
        sortedArray.push_back(i);
    }
    return sortedArray;
}

// Генератор обратно отсортированного массива
std::vector<int> generateReverseSortedArray(size_t size) {
    std::vector<int> reverseSortedArray;
    for (size_t i = size; i > 0; --i) {
        reverseSortedArray.push_back(i);
    }
    return reverseSortedArray;
}
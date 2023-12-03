#pragma once
#include <random>
#include <iostream>


std::vector<int> generateRandomArray(int lower_bound, int upper_bound, size_t size) {
    std::random_device rd;  // �������� ��������� �����
    std::mt19937 gen(rd()); // ��������� ��������� �����
    std::uniform_int_distribution<int> distribution(lower_bound, upper_bound); // ����������� �������������

    std::vector<int> randomArray;
    randomArray.reserve(size);

    for (size_t i = 0; i < size; ++i) {
        randomArray.push_back(distribution(gen)); // ��������� ���������� ����� � ���������� � ������
    }

    return randomArray;
}

// ��������� ���������������� �������
std::vector<int> generateSortedArray(size_t size) {
    std::vector<int> sortedArray;
    for (size_t i = 1; i <= size; ++i) {
        sortedArray.push_back(i);
    }
    return sortedArray;
}

// ��������� ������� ���������������� �������
std::vector<int> generateReverseSortedArray(size_t size) {
    std::vector<int> reverseSortedArray;
    for (size_t i = size; i > 0; --i) {
        reverseSortedArray.push_back(i);
    }
    return reverseSortedArray;
}
#pragma once
#include <iostream>
#include <vector>

#include "stats.h"


template<typename T>
Stats insertionSort(std::vector<T>& arr) {
	Stats stats;
	if (arr.size() < 2) return stats;
	for (size_t i = 1; i <= arr.size(); ++i) {
		size_t j = i - 1;
		while (j && arr[j] < arr[j - 1]) {
			stats.comparison_count++;
			std::swap(arr[j], arr[j - 1]);
			stats.copy_count += 2;
			--j;
		}
	}
	return stats;
}

template<typename T>
Stats cocktailSort(std::vector<T>& arr) {
	Stats stats;
	if (arr.size() < 2) return stats;
	size_t left = 0, right = arr.size() - 1;
	size_t last_swap = 0;
	while (left < right) {
		for (size_t i = left; i < right; ++i) {
			stats.comparison_count++;
			if (arr[i + 1] < arr[i]) {
				std::swap(arr[i + 1], arr[i]);
				stats.copy_count += 2;
				last_swap = i;
			}
		}
		right = last_swap;
		for (size_t j = right; j > left; --j) {
			stats.comparison_count++;
			if (arr[j] < arr[j - 1]) {
				std::swap(arr[j], arr[j - 1]);
				stats.copy_count += 2;
				last_swap = j;
			}			
		}
		left = last_swap;
	}
	return stats;	
}

template<typename T>
void merge(std::vector<T>& arr, size_t left, size_t mid, size_t right, Stats& stat) {
	
	size_t i = left; // первый элемент первого подмассива
	size_t j = mid + 1; // первый элемент второго подмассива

	std::vector<T> tmp; // временный массив для записи отсортированных элементов

	while (i <= mid && j <= right) {
		stat.comparison_count++;
		if (arr[i] < arr[j]) {
			tmp.push_back(arr[i++]);
			stat.copy_count++;
		}
		else {
			tmp.push_back(arr[j++]);
			stat.copy_count++;
		}
	}
	while (i <= mid) {
		tmp.push_back(arr[i++]);
		stat.copy_count++;
	}

	while (j <= right) {
		tmp.push_back(arr[j++]);
		stat.copy_count++;
	}

	for (size_t i = left; i <= right; ++i) {
		arr[i] = tmp[i - left];
		stat.copy_count++;
	}
}

template<typename T>
void mergeSort(std::vector<T>& arr, size_t left, size_t right, Stats& stat) {
	if (left < right) {
		size_t mid = left + (right - left) / 2;
		mergeSort(arr, left, mid, stat);
		mergeSort(arr, mid + 1, right, stat);

		merge(arr, left, mid, right, stat);
	}
}

template<typename T>
Stats nTWMergeSort(std::vector<T>& arr) {
	Stats stat;
	mergeSort(arr, 0, arr.size() - 1, stat);	
	return stat;
}

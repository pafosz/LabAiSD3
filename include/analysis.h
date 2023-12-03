#pragma once
#include <string>
#include <fstream>

#include "generator.h"
#include "sort.h"

Stats averageStats(int lower_bound, int upper_bound, size_t size, size_t num_arr, Stats(*sortingFunction)(std::vector<int>& arr)) {
	Stats aver_stat;

	for (size_t i = 0; i < num_arr; ++i) {
		std::vector<int> arr_i = generateRandomArray(lower_bound, upper_bound, size);
		aver_stat += sortingFunction(arr_i);
	}

	aver_stat /= num_arr;
	return aver_stat;
}

void getStats(int lower_bound, int upper_bound, size_t num_arr, const std::vector<size_t>& arr_len, Stats(*sortingFunction)(std::vector<int>& arr)) {
	for (int i = 0; i < arr_len.size(); ++i) {
		Stats stat = averageStats(lower_bound, upper_bound, arr_len[i], num_arr,  sortingFunction);
		std::cout << "Lenth: " << arr_len[i] << std::endl;
		std::cout << "Comparison count: " << stat.comparison_count << std::endl;
		std::cout << "Copy count: " << stat.copy_count << "\n" << std::endl;
	}
	std::cout << std::endl;
}

void getStatsSortArr(const std::vector<size_t>& arr_len, std::vector<int>(*generateFunction)(size_t length), Stats(*sortingFunction)(std::vector<int>& arr)) {
	for (size_t i = 0; i < arr_len.size(); ++i) {
		std::vector<int> arr = generateFunction(arr_len[i]);
		Stats stat = sortingFunction(arr);
		std::cout << "Lenth: " << arr_len[i] << std::endl;
		std::cout << "Comparison count: " << stat.comparison_count << std::endl;
		std::cout << "Copy count: " << stat.copy_count << "\n" << std::endl;
	}
	std::cout << std::endl;
}
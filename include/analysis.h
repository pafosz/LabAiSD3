#pragma once

#include "generator.h"
#include "sort.h"

Stats averageStats(int lower_bound, int upper_bound, int size, size_t num_arr, Stats(*sortingFunction)(std::vector<int>& arr)) {
	Stats aver_stat;

	for (size_t i = 0; i < num_arr; ++i) {
		std::vector<int> arr_i = generateRandomArray(lower_bound, upper_bound, size);
		aver_stat += sortingFunction(arr_i);
	}

	aver_stat /= num_arr;
	return aver_stat;
}
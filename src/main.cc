#include <string>
#include <fstream>
#include "../include/sort.h"
#include "../include/generator.h"
#include "../include/analysis.h"

template<typename T>
void printArr(std::vector<T> arr) {
	for (T num: arr) {
		std::cout << num << ' ';
	}
}

using namespace std;
int main() {
	/*std::vector<int> arr{ 1, 4, 7, 3, 9, 8, 5, 6, 2};
	printArr(arr);
	std::cout << std::endl;
	nTWMergeSort(arr);
	printArr(arr);

	cocktailSort(arr);
	printArr(arr);*/

	vector<size_t> lens_arr = { 1000, 2000, 3000, 4000, 5000, 10000, 25000, 50000 };
	int lower_bound = 1;
	int upper_bound = 50000;
	size_t num = 100;

	/*cout << "Statistics of the sorted array for cocktail sorting" << endl;
	getStatsSortArr(lens_arr, generateSortedArray, cocktailSort);
	cout << "Statistics of the sorted array for insertion sorting" << endl;
	getStatsSortArr(lens_arr, generateSortedArray, insertionSort);
	cout << "Statistics of the sorted array for merge sorting" << endl;
	getStatsSortArr(lens_arr, generateSortedArray, nTWMergeSort);
	cout << "Statistics of  back-sorted array for cocktail sorting" << endl;
	getStatsSortArr(lens_arr, generateReverseSortedArray, cocktailSort);
	cout << "Statistics of a back-sorted array for insertion sorting" << endl;
	getStatsSortArr(lens_arr, generateReverseSortedArray, insertionSort);
	cout << "Statistics of a back-sorted array for merge sorting" << endl;
	getStatsSortArr(lens_arr, generateReverseSortedArray, nTWMergeSort);
	cout << "Statistics for insertion sorting" << endl;
	getStats(lower_bound, upper_bound, num, lens_arr, insertionSort);
	cout << "Statistics for merge sorting" << endl;
	getStats(lower_bound, upper_bound, num, lens_arr, nTWMergeSort);*/

	cout << "the job is done" << endl;
}
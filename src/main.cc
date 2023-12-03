#include "../include/sort.h"
#include "../include/generator.h"
#include "../include/analysis.h"
template<typename T>
void printArr(std::vector<T> arr) {
	for (T num: arr) {
		std::cout << num << ' ';
	}
}


int main() {
	std::vector<int> arr{ 1, 4, 7, 3, 9, 8, 5, 6, 2};
	printArr(arr);
	std::cout << std::endl;
	nTWMergeSort(arr);
	printArr(arr);
	std::vector<int> arr = generateRandomArray(15, 1, 100);
	cocktailSort(arr);
	printArr(arr);

	
}
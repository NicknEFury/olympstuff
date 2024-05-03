#include <vector>  
#include <iostream>
#include <type_traits>

using namespace std;


/*
Insertion Sort
Best Case: n
Worst Case: n^2
Average Case: n^2
Space Complexity: 1
Stability: Yes
*/

void insertionSort(vector<int>& arr) {
	if (arr.empty()) {
		return;
	}  
	for (int i = 1; i < arr.size(); i++) {
		int key = arr[i];
		int j = i - 1;

		while (j < arr.size() && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}


/*
Selection Sort
Best Case: n^2
Worst Case: n^2
Average Case: n^2
Space Complexity: 1
Stability: No
*/

void selectionSort(int arr[], int n) {
	int temp = 0;
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
}


/*
Bubble Sort
Best Case: n
Worst Case: n^2
Average Case: n^2
Space Complexity: 1
Stability: Yes
*/

void bubbleSort(int arr[], int n) {
	int temp = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}


/*
Gnome Sort
Best Case: n
Worst Case: n^2
Average Case: n^2
Space Complexity: 1
Stability: Yes
*/

void gnomeSort(vector<int>& arr) {
	int n = arr.size(), temp;
	int index = 0;  
	while (index < n) {

		if (index == 0)
			index++;
		if (arr[index] >= arr[index - 1])
			index++;
		else {
			temp = arr[index];
			arr[index] = arr[index - 1];
			arr[index - 1] = temp;
			index--;
		}
	}
}


/*
Coctail Sort
Best Case: n
Worst Case: n^2
Average Case: n^2
Space Complexity: 1
Stability: Yes
*/

void cocktailSort(int arr[], int n) {
	bool swapped = true;
	int start = 0;
	int end = n - 1;  
	while (swapped) {
		swapped = false;  for (int i = start; i < end; i++) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}  if (!swapped) {
			break;  end--;  for (int i = end; i > start; i--) {
				if (arr[i] < arr[i - 1]) {
					std::swap(arr[i], arr[i - 1]);
					swapped = true;
				}
			}  start++;
		}
}

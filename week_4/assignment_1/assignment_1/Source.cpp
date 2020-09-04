#include <iostream>
#include <vector>
using namespace std;

/*
	bubble sort implementation
*/

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

vector<int> bubble(vector<int> arr) {
	bool noSwap = true;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size() - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				noSwap = false;
			}
		}
		if (noSwap) break;
	}
	return arr;
}



int main() {

	cout << "Please Enter Size of Array : ";
	int size = 0;
	cin >> size;
	int* arr = new int[size];
	// test 5 -2 1 7 9
	for (int i = 0; i < size; i++) {
		cout << "Please enter element at index " << i << " : " ;
		cin >> *(arr + i);
	}
	vector<int> arr_vec(arr, arr + size);
	vector<int> sorted = bubble(arr_vec);
	cout <<endl<< "[ ";
	for (int i = 0; i < sorted.size(); i++) {
		cout << sorted[i] << " ";
	}
	cout << "]";
	return 0;
}
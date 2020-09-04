#include <iostream>
#include <vector>
using namespace std;

/*
	reverse array
*/

void reversed_arr(vector<int> arr) {
	reverse(arr.begin(), arr.end());
	cout << endl << "[ ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "]";
}

int main() {
	start:
	cout << "Please Enter Size of Array : ";
	int size = 0;
	cin >> size; // 5
	if (size < 1 || size > 2e31 - 1) {
		cout << "invalid input please try again" << endl;
		goto start;
	}
	int* arr = new int[size];
	// test 1 2 3 4 5
	for (int i = 0; i < size; i++) {
		cout << "Please enter element at index " << i << " : ";
		cin >> *(arr + i);
	}
	vector<int> arr_vec(arr, arr + size);
	reversed_arr(arr_vec); // 5 4 3 2 1
	return 0;
}
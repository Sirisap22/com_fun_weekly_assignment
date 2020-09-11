#include <iostream>
#include <vector>
#define ld long double
using namespace std;

/*
	find a mean of values in the array
*/

ld computeMean(vector<ld> arr, int size) {
	ld total = 0;
	for (int i = 0; i < size; i++) {
		total += arr.at(i);
	}
	return total / size;
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
	ld* arr = new ld[size];
	// test 2.3 1.5 9.7 3.0 11
	for (int i = 0; i < size; i++) {
		cout << "Please enter element at index " << i << " : ";
		cin >> *(arr + i);
	}
	vector<ld> arr_vec(arr, arr + size);
	long double mean = computeMean(arr_vec, size);
	cout << "The mean is = " << mean; // 5.5
	return 0;
}
#include <iostream>
#define ll long long
using namespace std;

/*
	Product of elements in the array
*/

int product(int* arr, int size) {
	int ans = *arr;
	for (int i = 0; i < size; i++) {
		ans *= *(arr + i);
	}
	return ans;
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
	int ans = product(arr, size);

	cout << "Product of elements in the array is " << ans; // 120

	return 0;
}
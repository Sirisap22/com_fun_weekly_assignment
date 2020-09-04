#include <iostream>
using namespace std;

/*
    sum all elements in array
*/

int sum(int* arr, int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += *(arr + i);
	}
	return total;
}

int main() {
	cout << "Please Enter Size of Array : ";
	int size = 0;
	cin >> size; // 5
	int* arr = new int[size];
	// test 1 2 3 4 5
	for (int i = 0; i < size; i++) {
		cout << "Please enter element at index " << i << " : ";
		cin >> *(arr + i);
	}
	cout <<"The total sum of the elements in the array is : " << sum(arr, size); // ans = 10
	return 0;
}
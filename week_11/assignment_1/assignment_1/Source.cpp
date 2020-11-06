#include <iostream>
using namespace std;

// leetcode 896. Monotonic Array

char increaseOrDecrease(int diff) {
	if (diff < 0) return 'i';
	else if (diff > 0) return 'd';
	else return 'e';
}

int firstIncreaseOrDecrease(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		int diff = arr[i] - arr[i + 1];
		if (diff > 0 || diff < 0) return diff;
	}

	return 0;
}

bool isMonotonic(int* arr, int size) {
	if (size <= 2) return true;
	char type = increaseOrDecrease(firstIncreaseOrDecrease(arr, size));
	if (type != 'e') {
		for (int i = 0; i < size - 1; ++i) {
			char dtype = increaseOrDecrease(arr[i] - arr[i + 1]);
			if (dtype != type && dtype != 'e') return false;
		}
		return true;
	}
	return true;
}

int* input(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}
	return arr;
}

void output(bool isMono) {
	if (isMono) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;
}

/*

	test case

	case 1:
	input : 4
			1 2 2 3
	output: true

	case 2:
	input : 4
			6 5 4 4
	output: true

	case 3:
	input : 3
			1 3 2
	output: false

	case 4:
	input : 5
			1 2 3 4 5
	output: true

	case 5:
	input : 3
			1 1 1
	output: true

*/

int main() {
	int size;
	cin >> size;
	int* arr = input(size);
	output(isMonotonic(arr, size));
	return 0;
}

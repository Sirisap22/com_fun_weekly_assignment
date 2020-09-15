#include <iostream>
#include <vector>
using namespace std;

/* binary search (return index in a given 'sorted' array of the given target if target is not in the array return -1 )*/

int binarySearch(vector<int> arr, int target) {
	int right = arr.size() - 1;
	int left = 0;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] > target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

int main() {
start:
	cout << "Please Enter Size of Array : ";
	int size = 0;
	int target;
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
	cout << "Please Enter a Target to find : ";
	cin >> target; // 3
	vector<int> arr_vec(arr, arr + size);
	int ans = binarySearch(arr_vec, target);
	if (ans != -1) {
		cout << "The index of the target is = " << ans;
	} else {
		cout << "Sorry but a given target is not in the array";
	}
	return 0;
}
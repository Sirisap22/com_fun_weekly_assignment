#include <iostream>
#include <vector>
#define ld long double
using namespace std;

/* find a sum of squared values in given array */

ld squaredSum(vector<ld> arr) {
	ld ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		ans += (arr[i] * arr[i]);
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
	ld* arr = new ld[size] ;
	// test 1 2 3 4 5
	for (int i = 0; i < size; i++) {
		cout << "Please enter element at index " << i << " : ";
		cin >> *(arr + i);
	}
	vector<ld> arr_vec(arr, arr + size);
	ld ans = squaredSum(arr_vec);
	cout << "The squared sum of the array is = " << ans;
	return 0;
}
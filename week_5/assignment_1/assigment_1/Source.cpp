#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

/*
	implement radix sort ; input == positive integer3

*/

int getDigit(int num, int posi) {
    return  floor(fmod(abs(num), pow(10, posi + 1)) / pow(10, posi));
}

int digitCount(int num) {
    return to_string(abs(num)).length();
}

int mostDigits(vector<int> nums) {
    int most = 0;
    for (int i = 0; i < nums.size(); i++) {
        most = max(nums[i], digitCount(most));
    }

    return most;
}


vector<int> radix(vector<int> arr) {
	int len = mostDigits(arr);
	for (int i = 0; i < len; i++) {
		vector<vector<int>> buckets(10, vector<int>(10, -1));
		for (int j = 0; j < arr.size(); j++) {
			buckets[getDigit(arr[j], i)].push_back(arr[j]);
		}
		arr = {};
		for (auto a : buckets) {
			for (auto b : a) {
				if (b != -1) {
					arr.push_back(b);
				}
			}
		}
	}

	return arr;
}



void output(vector<int> arr) {
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
	// test 5 1 3 4 2
	for (int i = 0; i < size; i++) {
		cout << "Please enter element at index " << i << " : ";
		cin >> *(arr + i);
	}
	vector<int> arr_vec(arr, arr + size);
	vector<int> ans =  radix(arr_vec);
	output(ans); // 1 2 3 4 5
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// leetcode 1122. Relative Sort Array

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    int max = 0;
    for (int a : arr2) {
        if (a > max)
            max = a;
    }
    vector<int> order(max + 1, -1);
    for (int i = 0; i < arr2.size(); ++i)
        order[arr2[i]] = i;
    auto compare = [&order](const int a, const int b) -> bool {
        bool is_a_in_arr2 = false, is_b_in_arr2 = false;
        if (a < order.size() && order[a] != -1)
            is_a_in_arr2 = true;
        if (b < order.size() && order[b] != -1)
            is_b_in_arr2 = true;
        if (is_a_in_arr2 && is_b_in_arr2) {
            return order[a] < order[b];
        }
        else if (!is_a_in_arr2 && !is_b_in_arr2) {
            return a < b;
        }
        else if (is_a_in_arr2)
            return true;
        else
            return false;
    };
    sort(arr1.begin(), arr1.end(), compare);
    return arr1;
}

vector<int> input() {

    int size;
    cin >> size;

	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> *(arr + i);
	}
	vector<int> arr_vec(arr, arr + size);

	return arr_vec;
}

void output(vector<int>* ans) {
    cout << "[ ";
    for (int i = 0; i < ans->size() - 1; ++i) {
        cout << ans->at(i) << ", ";
    }
    cout << ans->at(ans->size() - 1) << " ]";
}

/*
    test case :
    input:  11
            2 3 1 3 2 4 6 7 9 2 19
            6
            2 1 4 3 9 6
    output: [ 2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19 ]
*/

int main() {
	
	vector<int> arr1 = input();
	vector<int> arr2 = input();
    output(&relativeSortArray(arr1,arr2));

	return 0;
}


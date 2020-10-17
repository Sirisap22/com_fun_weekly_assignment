#include <iostream>
#define ll long long
using namespace std;

// leetcode 1. two sum

ll* solve(ll* arr, ll target, ll size) {
	ll* ans = new ll[2];
	for (ll i = 0; i < size; i++) {
		for (ll j = i + 1; j < size; j++) {
			if (*(arr + i) + *(arr + j) == target) {
				ans[0] = i;
				ans[1] = j;
				return ans;
			}
		}
	}
	ans[0] = -1;
	ans[1] = -1;
	return ans;
}

void output(ll* ans) {
	cout << "[ " << *(ans) << ", " << *(ans + 1) << " ]" << endl;
}

ll* input(ll size) {
	ll* arr = new ll[size];
	for (ll i = 0; i < size; i++) {
		cin >> *(arr + i);
	}
	return arr;
}

/*
	test case

	case 1:
	input	2
			1 2
			3
	ans		[ 0, 1 ] // 1 + 2 == 3

	case 2:
	input	4
			2 7 11 15
			9
	ans		[ 0, 1 ] // 2 + 7 == 9

	case 3:
	input	3
			3 2 4
			6
	ans		[ 1, 2 ] // 2 + 4 == 6


*/

int main() {
	ll size, target;
	cin >> size; // size
	ll* arr = input(size);
	cin >> target;
	ll* ans = solve(arr, target, size);
	output(ans);
	return 0;
}
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

// leetcode 16.3Sum Closest
ll solve(ll* arr, ll target, ll size) {
	ll ans = 0;
	ll diff = LONG_MAX;
	for (ll i = 0; i < size; ++i) {
		for (ll j = i + 1; j < size; ++j) {
			for (ll k = j + 1; k < size; ++k) {
				ll sum = arr[i] + arr[j] + arr[k];
				ll currentDiff = abs(sum - target);
				if ( currentDiff < diff) {
					diff = currentDiff;
					ans = sum;
				}
			}
		}
	}

	return ans;
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
	input:	4
			-1 2 1 -4
			1
	output:	2

	case 2:
	input:	4
			-1 2 1 -4
			2
	output:	2

	case 3:
	input:	5
			5 3 2 -1 -4
			1
	output:	1

*/

int main() {
	ll size, target;
	cin >> size; // size
	ll* arr = input(size);
	cin >> target;
	ll ans = solve(arr, target, size);
	cout << ans;
	return 0;
}
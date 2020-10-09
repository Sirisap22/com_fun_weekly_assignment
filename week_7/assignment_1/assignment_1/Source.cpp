#include <iostream>
#define ll long long
using namespace std;

// leetcode 11.Container With Most Water

ll findArea(ll a, ll b, ll* arr) {
	if (a == b) return 0;
	ll maxHeight = *(arr + a) > * (arr + b) ? *(arr + b) : *(arr + a);
	return (b - a) * maxHeight;
}

ll maxArea(ll* arr, ll size) {
	ll ans = 0;
	for (ll i = 0; i < size; i++) {
		for (ll j = i; j < size; j++) {
			ll maybeAns = findArea(i, j, arr);
			ans = ans > maybeAns ? ans : maybeAns;
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

	test case 1:
	input:	9
			1 8 6 2 5 4 8 3 7
	output:	49

	test case 2:
	input:	2
			1 1
	output:	1

	test case 3:
	input:	5
			4 3 2 1 4
	output: 16

	test case 4:
	input:	3
			1 2 1
	output: 2		

*/

int main() {
	ll size;
	cin >> size;
	ll* water = input(size);
	cout << maxArea(water, size);
	return 0;
}
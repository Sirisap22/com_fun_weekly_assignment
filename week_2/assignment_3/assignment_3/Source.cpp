#include <iostream>
#define ll long long

/*
	Euler Project Problem 06
	Sum square difference
*/

ll sum_squares(ll x1, ll x2)
{
	ll total = 0;
	for (ll i = x1; i <= x2; i++)
	{
		total += i * i;
	}
	return total;
}

ll squares_sum(ll x1, ll x2)
{
	ll total = 0;
	for (ll i = x1; i <= x2; i++)
	{
		total += i;
	}
	return total * total;
}

int main()
{
	using namespace std;
	ll x, y;
	cout << "Enter the range to find sum squares difference (For the answer of the problem should use 1 100) : ";
	cin >> x >> y; // input 1 100;
	if (!(x < 0 || y < 0 || x > y)) {
		cout << "The Sum squares difference from " << x << " to " << y << " is :" << endl;
		cout << "Answer = " << squares_sum(x,y) << " - " << sum_squares(x,y) << " = "<<squares_sum(x, y) - sum_squares(x, y);
	}
	else {
		cout << "Invalid Input";
	}
	return 0;
}

/*
	ans = 25164150
*/
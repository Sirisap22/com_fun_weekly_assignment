#include <iostream>
#include <cmath>
#define ulli unsigned long long int

/*
	Project Euler Problem 05
	Smallest multiple
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/


bool isPrime(ulli n) {
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;
	ulli i;
	for (i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) return false;
	}
	return true;
}

ulli nth_prime_number(ulli nth)
{
	ulli count = 0;
	ulli i = 0;
	while (true)
	{
		if (isPrime(i)) count++;
		if (count == nth) break;
		i++;
	}
	return i;
}

ulli smallest_multiple(ulli k)
{
	using namespace std;
	ulli n = 1;
	ulli i = 1;
	bool check = true;
	long double limit = sqrt(k);
	ulli a[1000];
	while (nth_prime_number(i) <= k)
	{
		ulli p = nth_prime_number(i);
		a[i] = 1;
		if (check)
		{
			if (p <= limit)
			{
				a[i] = floor(log(k) / log(p));
			}
			else
			{
				check = false;
			}
		}
		n = n * pow(p, a[i]);
		++i;
	}
	return n;
}

int main()
{
	using namespace std;
	ulli k;
	cout << "Enter k to find smallest multiple of 1 to k (For the answer of the problem you should use 20) : ";
	cin >> k;
	cout << smallest_multiple(k);
	return 0;
}
/*
	ans = 232792560;
*/

/*
1st Version // Bad Time Complexity and Loop could go thought infinity times if the smallest mutilple in that range didn't exist.
bool isDivisible(int n, int i)
{
	return n % i == 0;
}
int smallest_multiple(int x,int y)
{
	int ans = y;
	bool found = false;
	while (!found)
	{
		for (int i = x; i <= y; i++) {
			if (!isDivisible(ans, i))
			{
				break;
			}
			if (i == y)
			{
				found = true;
			}
		}
		ans++;
	}

	return --ans;
}*/
#include <iostream>

/*
	Project Euler Problem 01

	Multiples of 3 and 5

	If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
	Find the sum of all the multiples of 3 or 5 below 1000.
*/

long solve(long n)
{
	long total = 0;
	for (long i = 1; i < n; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			total += i;
		}
	}

	return total;
}

int main()
{
	std::cout << solve(1000);
	return 0;
}

/*
	ans = 233168
*/
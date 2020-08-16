#include <iostream>
#include <vector>
#define ulli unsigned long long int

/*

	Project Euler Problem 03

	Largest prime factor

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

std::vector<ulli> factor(ulli num)
{
	std::vector<ulli> fac = {};
	for (ulli factor = 2; factor <= num / factor; factor++)
	{
		while (num % factor == 0)
		{
			num /= factor;
			fac.push_back(factor);
		}
	}
	if (num > 1) fac.push_back(num);

	return fac;
}

ulli solve(ulli n)
{
	//std::cout << n;
	ulli max = 0;
	std::vector<ulli> v = factor(n);
	for (auto x : v) {
		//std::cout << x;
		max = x > max ? x : max;
	}

	return max;
}

int main()
{
	std::cout << solve(600851475143);
	return 0;
}

/*
	ans = 6857
*/
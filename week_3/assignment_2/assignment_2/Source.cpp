#include <iostream> 
#define ll long long 
using namespace std; 

/*
	Euler Project Problem 10

	Summation of primes

	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

bool isPrime(ll n) { 
	if (n <= 1) return false; 
	if (n <= 3) return true; 
	if (n % 2 == 0 || n % 3 == 0) return false; 
	ll i; 
	for (i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) return false; 
	} 
	return true; 
} 

ll sumAllPrimesBelowN(ll n) { 
	ll total = 0; if (n < 1) return total; 
	for (ll i = 1; i < n; i++) { 
		if (isPrime(i)) total += i; 
	} 
	return total; 
} 

int main() { 
	ll n;
	cout << "Enter n to find sum of all primes below n (For the answer of the question should use 2000000): ";
	cin >> n;
	cout << "The Sum of all Primes below " << n<< " is " <<sumAllPrimesBelowN(n); 
	return 0;
}

/*
	ans = 142913828922
*/
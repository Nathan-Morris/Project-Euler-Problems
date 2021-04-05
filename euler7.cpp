// Project Euler #7
// https://projecteuler.net/problem=7
//
/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
*/

#include <iostream>
#include <climits>

#include <cmath> // for 'sqrt()'

using namespace std;

bool isPrime(unsigned long long l) {
    unsigned long long root_l = sqrtl(l) + 1;
    for (unsigned long long i = 2; i <= root_l; i++)
        if (!(l % i))
            return 0;
    return 1;
}

int main() {
    unsigned long long primeCount = 1, i;

    for (i = 3; i != ULLONG_MAX; i += 2)
        if (isPrime(i) && ++primeCount == 10001)
            break;

    cout << "Result: " << i << endl; // 104743
}
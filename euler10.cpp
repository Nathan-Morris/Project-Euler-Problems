// Project Euler #10
// https://projecteuler.net/problem=10
//
/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

#include <iostream>
#include <climits>

#include <cmath> // for 'sqrt()'

using namespace std;

/*
This is super slow compared to my others
cant think of any other ways to make it
slightly faster, just compile with 'Ofast'
*/

bool isPrime(unsigned long long l) {
    unsigned long long root_l = sqrtl(l) + 1;
    for (unsigned long long i = 2; i <= root_l; i++)
        if (!(l % i))
            return 0;
    return 1;
}

int main() {
    unsigned long long res = 2;

    for (unsigned long long i = 3; i != 2000001; i += 2) {
        if (isPrime(i)) {
            res += i;
        }
    }

    cout << "Result: " << res << endl; // 142913828922
}
// Project Euler #3
// https://projecteuler.net/problem=3
//
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <cmath> // for sqrt()

using namespace std;

//
// Note: Compiled With -Ofast due to long run time / 'bruting'
//

bool isPrimeBrute(unsigned long long l) {
    unsigned long long pRoot = sqrt(l) + 1;
    for (unsigned long long i = 2; i <= pRoot; i++) {
        if ((l % i) == 0)
            return false;
    }
    return 1;
}

int main() {
    const unsigned long long n = 600851475143L;
    const unsigned long long n_root = sqrt(n) + 1;

    unsigned long long factor = 0;

    for (unsigned long long l = 2; l <= n_root; l++) {
        if (n % l == 0) {
            if (isPrimeBrute(l)) {
                if (factor < l) {
                    factor = l;
                }
            }
        }
    }

    cout << "Result: " << factor << endl; // 6857
}
// Project Euler #2
// https://projecteuler.net/problem=2
//
// Each new term in the Fibonacci sequence is generated by adding the previous
// two terms. By starting with 1 and 2, the first 10 terms will be:
// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
// By considering the terms in the Fibonacci sequence whose values do not
// exceed four million, find the sum of the even-valued terms.

#include <iostream>

using namespace std;

int main() {
    unsigned long long fib1 = 1;
    unsigned long long fib2 = 2;
    unsigned long long sum = 0;

    while (fib1 < 4000000) {
        if (!(fib1 & 1)) {
            sum += fib1;
        }

        if (!(fib2 & 1)) {
            sum += fib2;
        }

        fib1 += fib2;
        fib2 += fib1;
    }
    
    cout << "Result: " << sum << endl; // 4613732
}
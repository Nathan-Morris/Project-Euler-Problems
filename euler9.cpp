// Project Euler #9
// https://projecteuler.net/problem=9
//
/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>
#include <climits>

#include <cmath> // for 'sqrt()'

// a   + b   + c   = 1000
// a^2 + b^2 = c^2
// --> to two variable system
// a   + b   + sqrt(a^2 + b^2) = 1000

using namespace std;

int main() {
    unsigned long long res = 0;

    for (unsigned int a = 1; a != 501; a++) {
        for (unsigned int b = 1; b != 501; b++) {
            if ( a + b + sqrt((a * a) + (b * b)) == 1000 ) {
                res = a * b * (1000 - a - b);
                break;
            }
        }
    }
    
    cout << "Result: " << res << endl; // 31875000
}
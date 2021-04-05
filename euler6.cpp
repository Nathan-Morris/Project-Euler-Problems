// Project Euler #6
// https://projecteuler.net/problem=6
//
/*
The sum of the squares of the first ten natural numbers is,
The square of the sum of the first ten natural numbers is,
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is .
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <iostream>
#include <climits>

using namespace std;

// inclusive range
int sumOfSquaresRange(int min, int max) {
    int sum = 0;
    do {
        sum += (min * min);
    } while (min++ != max);
    return sum;
}

// inclusive range
int squareOfSumRange(int min, int max) {
    int sum = 0;
    do {
        sum += min;
    } while (min++ != max);
    return sum * sum;
}

int main() {
    cout << "Result: " << sumOfSquaresRange(1, 100) - squareOfSumRange(1, 100) << endl; // -25164150, difference is '25164150'
}
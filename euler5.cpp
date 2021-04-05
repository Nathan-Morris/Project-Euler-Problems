// Project Euler #5
// https://projecteuler.net/problem=5
//
/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <iostream>
#include <climits>

using namespace std;

int main() {
    unsigned int res = 0;

    // only need to check factors that arent factors of other numbers
    // up to '20', dont need to check '20' as 'res' is incremented by it
    unsigned int chkFactors[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19 };

    while(1) {
loopLbl:
        res += 20;
        for (unsigned int factorIndex = 0; factorIndex < 9; factorIndex++) {
            if (res % chkFactors[factorIndex]) {
                goto loopLbl;
            }
        }
        break;        
    }

    cout << "Result: " << res << endl; // 232792560
}
// Project Euler #4
// https://projecteuler.net/problem=4
//
/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>

// ASCII '0' is 48 with each digit being 
// proportional to 48 with respect to '0'
#define DIGIT_TO_CHAR(c) (c + 48) 

using namespace std;

/*
Using a simple 'int -> string' conversion function seemed
like cheating so i just hashed together a not great but
workable function, no support for negative or maxes
*/

inline unsigned int tensPlaceCount(int i) {
    unsigned int plc = 0;
    do {
        plc++;
        i /= 10;
    } while(i);
    return plc;
}

bool intToCstr(int i, char* buf, unsigned int len, unsigned int* numLenBuf) {
    unsigned int numLen = tensPlaceCount(i);
    *numLenBuf = numLen;

    if (len < numLen + 1) {
        printf("Needed Buffer Of Length %u, Passed Buffer Len Was %u \n", numLen + 1, len);
        return 0;
    }

    buf[numLen] = '\0'; // null termination

    int digit;
    while (numLen--) {
        digit = i % 10;
        i /= 10;
        buf[numLen] = DIGIT_TO_CHAR(digit);
    }

    return 1;
}

// note 'len' is the 'strlen()', does not include '\0'
bool isCstrPalidrome(char* ptr, unsigned int len) {
    unsigned int halfLen = len / 2;
    for (unsigned int i = 0; i < halfLen; i++)
        if (ptr[i] != ptr[(len - 1) - i])
            return 0;
    return 1;
}

int main() {
    char numBuffer[7] = { 0, 0, 0, 0, 0, 0, 0 }; // 6 digits + null
    unsigned int numLen;
    int largest = 0, mult;

    // this runs fast enough to not worry about loop optimizations
    for (int i1 = 100; i1 < 1000; i1++) {
        for (int i2 = 100; i2 < 1000; i2++) {
            mult = i1 * i2;

            intToCstr(mult, numBuffer, 7, &numLen);

            if (isCstrPalidrome(numBuffer, numLen) && largest < mult) {
                largest = mult;
            }
        }
    }

   cout << "Result: " << largest << endl; // 906609
}
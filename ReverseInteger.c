/*
Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880/

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

# define LIMIT_UPPER pow(2, 31) - 1
# define LIMIT_LOWER pow(2, 31) * -1

int reverse(int x){
    char xStr[32];
    char reverseStr[32];
    bool isNeg = x < 0;
    int xSize = sprintf(xStr, "%d", x);
    long long int reversedX;
    
    if (isNeg) x *= -1;
    for (int i = 0; i < xSize; i++) {
        reverseStr[i] = xStr[xSize - i - 1];
    }
    reversedX = strtoll(reverseStr, NULL, 10);
    if (isNeg) {reversedX *= -1;}

    if (reversedX < LIMIT_LOWER || reversedX > LIMIT_UPPER) return 0;
    else return reversedX;
}

int main() {
    int num = 1534236469; // Number will overflow
    int numRev = reverse(num);
    printf("%d", numRev);
    return 0;
}
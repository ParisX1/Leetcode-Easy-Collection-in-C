/*
Power of Three

Solution
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/745/

Example 1:
Input: n = 27
Output: true
Explanation: 27 = 33

Example 2:
Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.

Example 3:
Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).

Constraints:
-2^31 <= n <= 2^31 - 1
*/
#include <stdbool.h>

bool isPowerOfThree(int n){
    long long int powerOfThree = 1;
    while (powerOfThree <= n) {
        if (n == powerOfThree) return true;
        powerOfThree *= 3;
    }
    return false;
}
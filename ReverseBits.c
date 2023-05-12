/*
Reverse Bits

Solution
Reverse bits of a given 32 bits unsigned integer.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/648/

Example 1:
Input: n = 00000010100101000001111010011100
Output: 964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

Example 2:
Input: n = 11111111111111111111111111111101
Output: 3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.

Constraints:
The input must be a binary string of length 32

Follow up: 
If this function is called many times, how would you optimize it?
*/

#include <stdint.h>
#include <stdio.h>
#include <math.h>

#define BINARY_LENGTH 32
#define BASE 2

uint32_t reverseBits(uint32_t n) {
    
    //printf("%zu", n);
    uint32_t result = 0;
    int bit;
    
    for (int exponent = BINARY_LENGTH -1; exponent >= 0; exponent--) {
        bit = n & 1;
        result += bit * pow(BASE, exponent);
        n = n >> 1;
    }
    return result;
}

/*
Approach here to to take each bit and raise to the power of the 
relevant position in the new uint32_t representation.  So, the 0th
bit is value^31, the 1th bit is value^30 etc
*/
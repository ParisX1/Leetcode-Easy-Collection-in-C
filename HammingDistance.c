/*
Hamming Distance

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/762/

Example 1:
Input: x = 1, y = 4

Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

Example 2:
Input: x = 3, y = 1
Output: 1

Constraints:
0 <= x, y <= 2^31 - 1
*/

#include<stdbool.h>

int hammingDistance(int x, int y){
    int countDiffs = 0;
    bool xBit;  // Current bit value (0, 1) for x 
    bool yBit;
    
    for (int i = 0; i < 32; i++) {
        xBit = x & 1;   // Value for the lsb
        yBit = y & 1;    
        countDiffs += xBit != yBit; // Increment count if lsb's are different
        x = x >> 1; // Shift bits right
        y = y >> 1;
    }
    return countDiffs;
    
    /*
    // Initial code to check bit-shifting
    int z = 10;
    printf("%d\n", z);
    printf("%d\n", z&1);
    z = z >> 1;
    printf("%d\n", z);
    printf("%d\n", z&1);
    return 1;
    */
}
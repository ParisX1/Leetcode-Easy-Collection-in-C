/*
Plus One

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* returnArr = (int*) malloc(sizeof(int) * digitsSize);
    int currentDigit;
    bool carryOver = 1;
    *returnSize = digitsSize;
    
    int i = digitsSize - 1; 

    while(i >= 0) {
        currentDigit = digits[i] + carryOver;
        if (currentDigit == 10){ 
            returnArr[i] = 0;
            carryOver = 1;
        } else {
            returnArr[i] = currentDigit;
            carryOver = 0;
        }
        i--;
    }

    // Check for spill-over -> reallocate array
    if (carryOver) {
        returnArr = (int*) realloc(returnArr, sizeof(int) * (digitsSize + 1));
        for (int i = 0; i < digitsSize; i++) {
            returnArr[i+1] = returnArr[i];
        }
        returnArr[0] = 1;
        *returnSize = ++digitsSize;
    }
    return returnArr;
}

int main() {
    int digitsSize = 1;
    // int digits[] = {1,2,3};
    int digits[] = {9};
    int solutionSize = 0;
    int* solution = plusOne(digits, digitsSize, &solutionSize);

    for (int i = 0; i < solutionSize; i++) {
        printf("%d\n", solution[i]);
    }
    free(solution);
}
/*
Single Number

Solution
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

Constraints:
1 <= nums.length <= 3 * 10^4
-3 * 10^4 <= nums[i] <= 3 * 10^4
Each element in the array appears twice except for one element which appears only once.
*/

#include <stdio.h>

#define NUM_DIGITS 19
#define SHIFT_FACTOR 9 // Rebase -9 to 0; -8 to 1, etc

int singleNumber(int* nums, int numsSize){
    int hashTable[NUM_DIGITS];
    int hashTableIndex;
    for (int i = 0; i < NUM_DIGITS; i++) hashTable[i] = 0;
    
    for (int i = 0; i < numsSize; i++) {
        hashTableIndex = nums[i] + SHIFT_FACTOR;
        hashTable[hashTableIndex]++;
    }
    
    for (int i = 0; i < NUM_DIGITS; i++) {
        if (hashTable[i] == 1) return i - SHIFT_FACTOR;
    }
    return 0;
}

// Add a hashmap !! implement you weakling !
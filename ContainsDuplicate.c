/*
Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

#include <stdlib.h>
#include <stdbool.h>

/*
See linux man page for qsort and comparison functions

The implementation of qsort can be found in The C Standard Library by Plauger pp357-358
There you can see how the function pointer is used for compare() 
*/ 

static int compare(const int* a, const int*b) {
    return *a - *b;
}

bool containsDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(nums[0]), compare);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) return true;
    }
    return false;
}
/*
Intersection of Two Arrays II

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/674/

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
 
Follow up:

* What if the given array is already sorted? How would you optimize your algorithm?
* What if nums1's size is small compared to nums2's size? Which algorithm is better?
* What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include<stdlib.h>

#define HASH_SIZE 1001

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int hashTable[HASH_SIZE] = {0};
    
    int index;
    for (int i = 0; i < nums1Size; i++) {
        index = nums1[i];
        hashTable[index]++;
    }
    
    int* intersectTable = NULL;
    int arraySize = 0;
    for (int i = 0; i < nums2Size; i++) {
        index = nums2[i];
        if (hashTable[index] > 0) {
            arraySize++;
            hashTable[index]--;
            if (arraySize == 1) intersectTable = (int*) malloc(sizeof(int));
            else                intersectTable = (int*) reallocarray(intersectTable, arraySize, sizeof(int));
            intersectTable[arraySize - 1] = nums2[i];
        }
    }
    *returnSize = arraySize;
    return intersectTable;
}
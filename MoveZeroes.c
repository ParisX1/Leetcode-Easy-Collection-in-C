/*
Move Zeroes

Solution
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:
1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1

Follow up: Could you minimize the total number of operations done?
*/

#include <stdio.h>

void shuffleDown(int* nums, int start, int stop);

void moveZeroes(int* nums, int numsSize){
    
    if (numsSize == 1) return;
    
    int i = 0;
    
    // Set j to first non-zero
    int j = numsSize - 1;
    while (nums[j] == 0 && j > 0) j--;

    // Iterate over list and move zeros to end
    while (i < j) {
        while (nums[i] == 0) {
            shuffleDown(nums, i, j);        
            nums[j] = 0;
            j--;
        }
        i++;
    }
}

/***
 * Shuffle all the elements in nums one to the left from start to stop
*/
void shuffleDown(int* nums, int start, int stop) {
    while (start < stop) {
        nums[start] = nums[start+1];
        start++;
    }
}

int main() {
    int nums1[] = {0, 1, 0, 3, 12};
    int numsSize1 = 5;  
    moveZeroes(nums1, numsSize1);
    for (int i = 0; i < numsSize1; i++) printf("%d \n", nums1[i]);

    printf("~~~~\n");

    int nums2[] = {0, 0, 1};
    int numsSize2 = 3;  
    moveZeroes(nums2, numsSize2);
    for (int i = 0; i < numsSize2; i++) printf("%d \n", nums2[i]);

    printf("~~~~\n");

    int nums3[] = {0, 0};
    int numsSize3 = 2;  
    moveZeroes(nums3, numsSize3);
    for (int i = 0; i < numsSize3; i++) printf("%d \n", nums3[i]);

    return 0;
}
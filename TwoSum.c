/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* solution = (int*) malloc(sizeof(int) * 2);
    int remainder; // Target to find given nums[i]
    
    //sort(nums);
    for (int i = 0; i < numsSize - 1; i++){
        remainder = target - nums[i];
        for (int j = i + 1; j < numsSize; j++){
            if (nums[j] == remainder) {
                solution[0] = i;
                solution[1] = j;
                return solution;
            }
        }
    }
    return solution;
}

int main() {

    int size = 4;

    int nums[] = {2,7,11,15};
    int* solution;
    solution = twoSum(nums, size, 9, &size);

    for (int i = 0; i < 2; i++) {
        printf("%d \n", solution[i]);
    }
    free(solution);
    return 0;
}


/*
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/
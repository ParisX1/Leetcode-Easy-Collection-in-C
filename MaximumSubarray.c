/*
Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/566/

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <stdio.h>

int maxSubArray(int* nums, int numsSize){

    // Start left end and right end to find best starting and ending point
    // Eg from right-end, if the sum is positive, include

    //if (numsSize == 1 ) return nums[0];

    int startSum = nums[0];
    int endSum = 0;
    //if (numsSize > 1) endSum = nums[numsSize-1];
    
    int midPoint = numsSize / 2;
    
    for (int i = 1; i < midPoint; i++) {
        if (startSum + nums[i] > nums[i]) startSum = startSum + nums[i];
        else startSum = nums[i];
    }

    for (int i = numsSize - 1; i >= midPoint; i--) {
        if (endSum + nums[i] > nums[i]) endSum = endSum + nums[i];
        else endSum = nums[i];
    }

    printf("startSum: \t%d \nendSum: \t%d \n", startSum, endSum);

    int totalSum = startSum + endSum;
    if (totalSum > startSum && totalSum > endSum) return totalSum;
    else {
        if (startSum > endSum) return startSum;
        else return endSum;
    }
    /*
    if (startSum + endSum > startSum) return startSum + endSum;
    else {
        if (startSum > endSum) return startSum;
        else return endSum;
    }
    */
}

int main() {
    /*
    int input01[] = {-2,1,-3,4,-1,2,1,-5,4};
    int input01Size = 9;
    int input01Solution = 6;
    int result = maxSubArray(input01, input01Size);
    printf("Result: \t%d \nSolution: \t%d \n", result, input01Solution);
    */
    printf("~~~\n");

    int input02[] = {-2,1};
    int input02Size = 2;
    int input02Solution = 1;
    int result02 = maxSubArray(input02, input02Size);
    printf("Result: \t%d \nSolution: \t%d \n", result02, input02Solution);

}
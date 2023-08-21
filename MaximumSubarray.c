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

int max(int num1, int num2) {
    if (num1 > num2)    return num1;
    else                return num2;
}

int maxSubArray(int* nums, int numsSize){
    int currentNum;
    int maxSum  = nums[0];  // The current max sub-array sum
    int nextSum = nums[0];  // "Lookahead" for a larger sub-array
    for (int i = 1; i < numsSize; i++) {
        currentNum  = nums[i];
        nextSum     = max(currentNum, nextSum + currentNum);    // Look for something bigger to replace maxSum
        maxSum      = max(maxSum, nextSum);                     // Update maxSum if we find something bigger
    }
    return maxSum;
}

// Note: when nextSum > maxSum, we are essentially "setting" nextSum = maxSum, as maxSum = max(v1, v2)
// So we don't need an if (nextSum > nextSum), this is taken care of in the max()

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
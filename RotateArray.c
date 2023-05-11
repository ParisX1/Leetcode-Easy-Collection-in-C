/*
Rotate Array

Solution
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10*5
 

Follow up:

* Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
* Could you do it in-place with O(1) extra space?
*/

void rotate(int* nums, int numsSize, int k){
    int ptr;
    int newArr[numsSize];
    
    for (int i = 0; i < numsSize; i++) {
        ptr = (k + i) % numsSize;
        newArr[ptr] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = newArr[i];
    }
    
}

/*
Input:  [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
*/
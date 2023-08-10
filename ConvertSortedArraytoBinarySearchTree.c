/*
Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/631/

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:
* 1 <= nums.length <= 10^4
* -10^4 <= nums[i] <= 10^4
* nums is sorted in a strictly increasing order.
*/

#include<stdio.h>
#include<stdlib.h>

 //* Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int valueToAdd) {
    struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    newNode->val = valueToAdd;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
    
struct TreeNode* bstRecursive(int* nums, int i, int j) {
    if (j < i) return NULL;
    int medianIndex = (i + j) / 2;
    int mediumValue = nums[medianIndex];
    struct TreeNode* newNode = createNode(mediumValue);
    newNode->left  = bstRecursive(nums, i, medianIndex - 1);
    newNode->right = bstRecursive(nums, medianIndex + 1, j);
    return newNode;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return bstRecursive(nums, 0, numsSize - 1);
}

int main() {
    int nums[] = {-10,-3,0,5,9};
    int size = 5;
    sortedArrayToBST(nums, size);
    return 0;
}
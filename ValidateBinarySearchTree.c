/*
Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/625/

Constraints:

The number of nodes in the tree is in the range [1, 104].
-2^31 <= Node.val <= 2^31 - 1
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool validBSTHelper(struct TreeNode* node, long long int minVal, long long int maxVal);

bool isValidBST(struct TreeNode* root){
    long long int minVal = LLONG_MIN;
    long long int maxVal = LLONG_MAX;
        
    if (root == NULL) {
        return true;
    }
    
    return validBSTHelper(root, minVal, maxVal);
}

bool validBSTHelper(struct TreeNode* node, long long int minVal, long long int maxVal) {
    //printf("min: %d \n", minVal);
    //printf("max: %d \n", maxVal);
    if (node == NULL) {
        return true;
    }
    if (node->val <= minVal || node->val >= maxVal) {
        return false;
    }
    return validBSTHelper(node->left, minVal, node->val) && validBSTHelper(node->right, node->val, maxVal);
}
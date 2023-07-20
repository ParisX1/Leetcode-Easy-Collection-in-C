/*
Symmetric Tree

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/627/
*/

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

bool isSymmetricRecursive(struct TreeNode* leftNode, struct TreeNode* rightNode);

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return false;
    return isSymmetricRecursive(root->left, root->right);
}

bool isSymmetricRecursive(struct TreeNode* leftNode, struct TreeNode* rightNode){
    if (leftNode == NULL && rightNode == NULL) return true;
    if ((leftNode == NULL && rightNode != NULL) || (leftNode != NULL && rightNode == NULL)) return false;
    if (leftNode->val != rightNode->val) return false;
    return isSymmetricRecursive(leftNode->left, rightNode->right) && 
        isSymmetricRecursive(leftNode->right, rightNode->left);
}
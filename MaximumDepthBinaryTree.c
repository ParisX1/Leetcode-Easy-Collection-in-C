/**
Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/555/

*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
// Not needed.  Copied my solution to Gatech DSA course
int depthSearch(struct TreeNode* node, int depthCounter) {
    depthCounter++;
    if (node->left != NULL) { depthSearch(node->left, depthCounter);}
    if (node->right != NULL) { depthSearch(node->right, depthCounter);}
    return depthCounter++;
}
*/
int maxDepth(struct TreeNode* root){
    //return depthSearch(root, 0);

    if (root == NULL) {return 0;}
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    if (leftHeight > rightHeight) {return leftHeight + 1;}
    else {return rightHeight + 1;}

    // I also came up with the below when I did a second time:
    /*
    if (root == NULL) {return 0;}
    int maxLeft =   1 + maxDepth(root->left);
    int maxRight =  1 + maxDepth(root->right);
    if (maxLeft > maxRight) {return maxLeft;}
    else                    {return maxRight;}
    */

}

int main() {
    struct TreeNode root;
    struct TreeNode right;

    root.val = 1;
    right.val = 2;
    root.left = NULL;
    root.right = &right;
    right.left = NULL; 
    right.right = NULL;

    int deepest = maxDepth(&root);
    printf("%d", deepest);

    return 0;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }
    if (root->left != NULL && root->left->val >= root->val) {
        return false;
    }
    else if (root->right != NULL && root->right->val <= root->val) {
        return false;
    }
    else {
        return isValidBST(root->left);
        return isValidBST(root->right);
    }
}
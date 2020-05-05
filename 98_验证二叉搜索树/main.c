/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 }TreeNode;

bool check_bst(struct TreeNode* root, long min, long max)
{
    long num = 0;
    if (root == NULL) {
        return true;
    }
    num = root->val;
    if (num <= min || num >= max) {
        return false;
    }

    if (!check_bst(root->left, min, num)) {
        return false;
    }

    if (!check_bst(root->right, num, max)) {
        return false;
    }
    return true;
}

bool isValidBST(struct TreeNode* root){
    if (root == NULL) {
        return true;        
    }
    return check_bst(root, 0x8000000000000000, 0x7FFFFFFFFFFFFFFF);
}
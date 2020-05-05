/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void get_result2(struct TreeNode* node, int sum, int *p_result, int temp_sum)
{
    if (node == NULL) {
        return;
    }

    temp_sum += node->val;
    if (temp_sum == sum) {
        (*p_result)++;
    }
    get_result2(node->left, sum, p_result, temp_sum);
    get_result2(node->right, sum, p_result, temp_sum);
}

void get_result1(struct TreeNode* node, int sum, int *p_result)
{
    if (node == NULL) {
        return;
    }
    get_result2(node, sum, p_result, 0);
    get_result1(node->left, sum, p_result);
    get_result1(node->right, sum, p_result);
}


int pathSum(struct TreeNode* root, int sum){
    int result = 0;

    if (root == NULL) {
        return 0;
    }

    get_result1(root, sum, &result);

    return result;
}
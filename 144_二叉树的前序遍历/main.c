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

int g_index = 0;
int g_node_cnt = 0;

void traversal(struct TreeNode* root, int *result)
{
    if (root == NULL) {
        return;
    }

    if (g_index < g_node_cnt) {
        result[g_index] = root->val;
        g_index++;
    }
    traversal(root->left, result);
    traversal(root->right, result);
}
int get_node_cnt(struct TreeNode* root)
{
    int node_cnt = 0;
    if (root == NULL) {
        return 0;
    }
    node_cnt++;
    node_cnt += get_node_cnt(root->left);
    node_cnt += get_node_cnt(root->right);
    return node_cnt;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *result = NULL;
    if (root == NULL || returnSize == NULL) {
        *returnSize = 0;
        return NULL;
    }
    g_index = 0;
    (*returnSize) = get_node_cnt(root);
    g_node_cnt = (*returnSize);
    result = (int*)malloc((*returnSize) * sizeof(int*));
    traversal(root,result);
    return result;
}
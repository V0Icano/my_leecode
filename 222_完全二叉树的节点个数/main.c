/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int g_node_cnt = 0;
void get_node_cnt(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    g_node_cnt++;
    get_node_cnt(root->left);
    get_node_cnt(root->right);
}

int countNodes(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    g_node_cnt = 0;
    get_node_cnt(root);
    return g_node_cnt;
}
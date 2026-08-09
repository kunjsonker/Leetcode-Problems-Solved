/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int maxval) {
        if (root == NULL)
            return 0;

        int count = 0;

        if (root->val >= maxval) {
            count = 1;
        }

        maxval = max(maxval, root->val);

        int lh = dfs(root->left, maxval);
        int rh = dfs(root->right, maxval);

        return count + lh + rh;
    }

    int goodNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        return dfs(root, root->val);
    }
};
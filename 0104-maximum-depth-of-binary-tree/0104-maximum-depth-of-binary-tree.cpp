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
    int count=0;
    int maxDepth(TreeNode* root) {
        //this can be solved using dfs and queue
        //recursion technique is much more easy but difficult to build
        
        if(root==NULL) return NULL;
        
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return 1+max(left,right);

        
    }
};
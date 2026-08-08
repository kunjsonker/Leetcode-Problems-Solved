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
    int ans=0;
public:
    
    int height(TreeNode* root){
        if(root ==NULL) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        ans=max(ans,1+lh+rh);
        return 1+max(lh,rh);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        //first implement the function of taking out the height of a binary tree
        //now use modified version of it
        int data=height(root); //just used to call the function
        return ans-1;
        
        



        
        

        


        
    }
};
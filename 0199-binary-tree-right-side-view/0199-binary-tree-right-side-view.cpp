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
    vector<int> rightSideView(TreeNode* root) {
        //this can be done using bfs or level order traversal

        vector<vector<int>>ans;
        if(root==NULL) return {};

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            vector<int>temp;
            int n=q.size();
            for(int i=0;i<n;i++){

            
            TreeNode* t=q.front();
            temp.push_back(t->val);
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            
            }
            ans.push_back(temp);

        }

        int size=ans.size();
        vector<int>anss;
        for(int i=0;i<size;i++){
            
            anss.push_back(ans[i].back());
        }

        return anss;

        
    }
};
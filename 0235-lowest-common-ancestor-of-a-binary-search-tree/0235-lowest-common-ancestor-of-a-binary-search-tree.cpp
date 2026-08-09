/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //it is a BST so it will be easier for path to find
        //in a BST so left node will be smaller than root and right will be bigger
        //take two vectors of treenode and push the nodes while traversing the path
        TreeNode* temp1=root;
        TreeNode* temp2=root;
        vector<TreeNode* > v1;
        vector<TreeNode* > v2;


        while(temp1->val!=p->val){
            if(p->val<temp1->val){
                v1.push_back(temp1);
                temp1=temp1->left;

                
                
            }
            else{
                v1.push_back(temp1);
                temp1=temp1->right;

            }
        }
        v1.push_back(temp1);

        while(temp2->val!=q->val){
            if(q->val<temp2->val){
                v2.push_back(temp2);
                temp2=temp2->left;

                
                
            }
            else{
                v2.push_back(temp2);
                temp2=temp2->right;

            }
        }
        v2.push_back(temp2);

        int m=v1.size();
        int n=v2.size();

        if(n<m){
            int temp=m;
            m=n;
            n=temp;
        } 
        TreeNode* temp=v1[0];

        for(int i=0;i<m;i++){
            

            if(v1[i]->val==v2[i]->val){
                temp=v1[i];
            }
            else{
                break;
            }


        }
        return temp;





        
        
        
    }
};
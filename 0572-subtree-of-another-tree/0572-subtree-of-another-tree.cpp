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
    vector<string> v1;
    vector<string> v2;

public:
    void preOrder(TreeNode* root, vector<string>& v) {
        if (root == nullptr) {
            v.push_back("#");  // null marker
            return;
        }

        v.push_back(to_string(root->val));
        preOrder(root->left, v);
        preOrder(root->right, v);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        preOrder(root, v1);
        preOrder(subRoot, v2);

        int n = v1.size();
        int m = v2.size();

        // Check whether v2 occurs inside v1
        for (int i = 0; i <= n - m; i++) {
            bool found = true;

            for (int j = 0; j < m; j++) {
                if (v1[i + j] != v2[j]) {
                    found = false;
                    break;
                }
            }

            if (found)
                return true;
        }

        return false;
    }
};
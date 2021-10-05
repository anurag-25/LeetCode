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
private: 
    int mx = INT_MIN;
public:
    int post (TreeNode* node) {
        if (node==NULL) return 0;
        int left = max (post (node->left), 0);
        int right = max (post (node->right), 0);
        mx = max (mx, left+right+node->val);
        return node->val + max (left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        if (root==NULL) return 0;
        mx = INT_MIN;
        post (root);
        return mx;
    }
};
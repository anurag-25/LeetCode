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
    int count (TreeNode* root, int mx) {
        if (root==NULL) return 0;
        int temp = count(root->left, max (mx, root->val)) + count (root->right, max (mx, root->val));
        if (root->val < mx) return temp;
        return temp + 1;
    }
    
    int goodNodes(TreeNode* root) {
        if (root==NULL) return 0;
        int mx = root->val;
        return count (root, mx);
    }
};
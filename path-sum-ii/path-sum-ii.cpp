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
    void solve (TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> &curr) {
        curr.push_back (root->val);
        
        if (root->val==targetSum && !root->left && !root->right) {
            ans.push_back (curr);
        }
        if (root->left) solve (root->left, targetSum-root->val, ans, curr);
        if (root->right) solve (root->right, targetSum-root->val, ans, curr);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if (root==NULL) return ans;
        vector<int> curr;
        solve (root, targetSum, ans, curr);
        return ans;
    }
};
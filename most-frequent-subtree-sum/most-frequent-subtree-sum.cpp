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
    int get_freq (TreeNode* root, unordered_map <int, int> &m, int &mx) {
        if (root==NULL) return 0;
        int left = get_freq (root->left, m, mx);
        int right = get_freq (root->right, m, mx);
        int currNodeSum = left+right+root->val;
        m[currNodeSum]++;
        mx = max (mx, m[currNodeSum]);
        return currNodeSum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map <int, int> m;
        int mx = INT_MIN;
        get_freq (root, m, mx);
        
        vector<int> ans;
        for (auto p: m) {
            if (p.second == mx) ans.push_back (p.first);
        }
        return ans;
    }
};
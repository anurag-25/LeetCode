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
    void inorder (TreeNode *root, vector <int> &ans) {
        if (root == NULL) return;
        inorder (root->left, ans);
        ans.push_back (root->val);
        inorder (root->right, ans);
    }
    
    bool isValidBST(TreeNode* root) {
        vector <int> in;
        inorder (root, in);
        for (int i=0; i<in.size()-1; i++) 
            if (in[i+1] <= in[i]) return false;
        return true;
    }
};
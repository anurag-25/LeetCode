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
    void solve (TreeNode* root, int &sum, int currNum) {
        currNum = currNum*10+root->val;
        if (root->left==NULL && root->right==NULL) {
            sum += currNum;
            return;
        }
        if (root->left) solve (root->left, sum, currNum);
        if (root->right) solve (root->right, sum, currNum);
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0, currNum = 0;
        solve (root, sum, currNum);
        return sum;
    }
};
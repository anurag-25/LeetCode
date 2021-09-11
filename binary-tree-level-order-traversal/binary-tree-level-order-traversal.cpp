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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector<int>> ans;
        if (root == NULL) return ans;
        queue <TreeNode *> q;
        q.push(root);
        int j = 0; 
        while (!q.empty() ) {
            vector <int> temp;
            int nodesAtCurr = q.size();
            j=0;
            while (j<nodesAtCurr) {
                TreeNode *currNode = q.front();
                if (currNode->left) q.push(currNode->left);
                if (currNode->right) q.push(currNode->right);
                q.pop();
                temp.push_back (currNode->val);
                j++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
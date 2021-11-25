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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map <int, map<int,multiset<int>> > m;
        queue < pair<TreeNode*,pair<int, int>> > q;
        q.push ( {root, {0,0}} );
        
        TreeNode* temp;
        int level =0, col = 0;
        while (!q.empty()) {
            temp = q.front().first;
            level =q.front().second.first, col = q.front().second.second;
            q.pop();
            m[col][level].insert( temp->val );
            if (temp->left) q.push ({temp->left, {level+1, col-1}} );
            if (temp->right) q.push ({temp->right, {level+1, col+1}} );
        }
        
        vector<vector<int>> ans;
        for (auto colMap: m) {
            vector<int> curr;
            for (auto colLevelMap: colMap.second) {
                for (auto x: colLevelMap.second) {
                    curr.push_back (x);
                }
                    
            }
            ans.push_back (curr);
        }
        return ans;
    }
};
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
    // int kthSmallest(TreeNode* root, int k) {
    //     TreeNode* curr = root;
    //     stack<TreeNode*> nodes;
    //     while(!nodes.empty() || curr != nullptr) {
    //         while(curr!=nullptr) {
    //             nodes.push(curr);
    //             curr = curr->left;
    //         }
    //         TreeNode* temp = nodes.top();
    //         nodes.pop();
    //         if(--k == 0) {
    //             return temp->val;
    //         }
    //         curr = temp->right;
    //     }
    //     return -1;
    // }
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> inorder;
        TreeNode* curr = root;
        
        while (!inorder.empty() || curr ) {
            while (curr) {
                inorder.push(curr);
                curr = curr->left;
            }
            TreeNode* temp = inorder.top();
            inorder.pop();
            if (--k == 0) return temp->val;
            curr = temp->right;
            
            
        }
       return -1;
    }
};


// int solve (TreeNode* root, int &k) {
//     if (root==NULL) return -1;
//     int left = solve (root->left, k);
//     if (left !=-1 ) return left;
//     if (--k == 0) return root->val;
//     return solve (root->right, k);
// }
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         return solve (root, k);
//     }
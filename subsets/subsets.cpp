class Solution {
public:
    void solve (vector <int> &curr, vector<vector<int>> &ans, vector <int> &nums, int i){
        if (i==nums.size()) {
            ans.push_back (curr);
            return;
        }
        // not include ith element
        solve(curr, ans, nums, i+1);
        
        // include ith
        // vector <int> curr2 (curr);
        curr.push_back (nums[i]);
        solve (curr, ans, nums, i+1);
        curr.pop_back();
        return;
    } 
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> ans;
        vector <int> curr;
        solve (curr, ans, nums, 0);
        return ans;
    }
};
class Solution {
public:
    void solve (vector<vector<int>> &ans, vector <int> &nums, int fixed) {
        if (fixed == nums.size()-1) {
            ans.push_back (nums);
            return;
        }
        for (int i=fixed; i<nums.size(); i++) {
            swap (nums[fixed], nums[i]);
            solve (ans, nums, fixed+1);
            swap (nums[fixed], nums[i]);
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> ans;
        solve (ans, nums, 0);
        return ans;
    }
};
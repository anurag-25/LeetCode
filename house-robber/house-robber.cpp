class Solution {
public:
    int solve (vector<int> &nums, vector<int> &dp, int curr) {
        if (curr<0) return 0;
        if (dp[curr] != -1) return dp[curr];
        else return dp[curr] = max (solve(nums, dp, curr-2)+nums[curr], solve (nums, dp, curr-1));
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp (n, -1);
        return solve (nums, dp, n-1);
    }
};
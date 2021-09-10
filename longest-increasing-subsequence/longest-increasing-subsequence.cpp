class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return 1;
        vector <int> ans (n, 1);
        int mx =1, res =1;
        for (int i=1; i<n; i++) {
            mx = 1;
            for (int j=0; j<i; j++) {
                if (nums[j] < nums[i] ) mx = max (mx, 1+ans[j]);
            }
            ans[i] = mx;
            res = max (mx, res);
        }
        return res;
    }
};
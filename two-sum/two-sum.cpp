class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), res =0;
        if (n<3) return 0;
        
        vector <int> ans (n, 0);
        
        for (int i=2; i<n; i++) {
            if (nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                ans[i] = 1 + ans[i-1];
                res += ans[i];
            }
        }
        return res;
    }
};

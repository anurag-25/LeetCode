class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int &x: nums) 
            if (x<=0) x = n+1;
        for (int i=0; i<n; i++) {
            if (abs(nums[i]) > n) continue;
            int &x = nums[abs(nums[i]) - 1];
            if (x>0) x = -x;
        }
        for (int i=0; i<n; i++)
            if (nums[i]>=0) return i+1;
        return n+1;
    }
};
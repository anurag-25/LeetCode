class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        for (int i=0; i<nums.size()-1; i++) {
            if (i<=maxReachable) maxReachable = max (maxReachable, i+nums[i]);
            if (maxReachable >= nums.size()-1) return true;
        }
        if (maxReachable >= nums.size()-1) return true;
        return false;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0];
        for (int i=0; i<n; i++) {
            curr = abs(nums[i]);
            if (nums[curr-1]<0) break;
            else nums[curr-1] = -nums[curr-1];
        }
        return curr;
    }
};
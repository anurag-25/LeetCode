class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int> {-1,-1};
        int first_occur = -1, left = 0, right =nums.size()-1, mid =0;
        while (left <= right) {
            mid = left + (right-left)/2;
            if (nums[mid] == target) {
                first_occur = mid;
                right = mid-1;
            }
            else if (nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        int last_occur = -1;
        left = 0; 
        right =nums.size()-1;
        while (left <= right) {
            mid = left + (right-left)/2;
            if (nums[mid] == target) {
                last_occur = mid;
                left = mid+1;
            }
            else if (nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return vector<int> {first_occur, last_occur};
    }
};
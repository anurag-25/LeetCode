class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left =0, right = n-1, mid;
        while (left < right) {
            mid = left+(right-left)/2;
            if (nums[mid] < nums[right]) right = mid;
            else left = mid+1;
        }
        int k = left;
        if (target<=nums[n-1] && target >=nums[k]) {
            left = k;
            right = n-1;
        }
        else {
            left = 0;
            right = k;
        }
        while (left <= right) {
            mid = left+(right-left)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
        return -1;
    }
};
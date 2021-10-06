class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = INT_MIN, left = 0, right = n-1;
        while (left<right) {
            ans = max (ans, min(height[left], height[right])*(right-left) );
            if (height[left] < height[right]) left++;
            else right--;
        }
        return ans;
    }
};
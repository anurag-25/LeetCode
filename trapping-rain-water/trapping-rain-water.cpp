class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector <int> l (n, 0);
        vector <int> r (n, 0);
        
        int leftMax = height[0], rightMax =height[n-1];
        for (int i=1; i<n; i++) {
            l[i] = leftMax;
            leftMax = max (leftMax, height[i]);
        }
        for (int i=n-2; i>=0; i--) {
            r[i] = rightMax;
            rightMax = max (rightMax, height[i]);
        }
        int water, ans = 0;
        for (int i=0; i<n; i++) {
            water = min(l[i], r[i]) - height[i];
            if (water>0) ans+= water;
        }
        return ans;
    }
};
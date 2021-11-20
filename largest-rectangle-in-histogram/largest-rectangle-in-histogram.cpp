class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left (n), right(n);
        left[0] = -1;
        right[n-1] = n;
        for (int i=1; i<n; i++) {
            int j = i-1;
            while (j>=0 && heights[j]>=heights[i] ) j = left[j];
            left[i] = j;
        }
        int ans = max (0, heights[n-1]*(right[n-1]-left[n-1]-1) );
        for (int i=n-2; i>=0; i--) {
            int j = i+1;
            while (j<n && heights[j]>=heights[i] ) j = right[j];
            right[i] = j;
            
            ans = max (ans, heights[i]*(right[i]-left[i]-1)); 
        }
        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX,  mx = 0;
        for (int x: prices) {
            mn = min (x, mn);
            mx = max (x-mn, mx);
        }
        return mx;
    }
};
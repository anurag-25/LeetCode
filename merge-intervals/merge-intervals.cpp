class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort (intervals.begin(), intervals.end());
        int lStart = intervals[0][0], lEnd = intervals[0][1];
        
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] <= lEnd) {
                lStart = min (lStart, intervals[i][0]);
                lEnd = max (lEnd, intervals[i][1]);
            }
            else {
                ans.push_back(vector<int>{lStart, lEnd});
                lStart = intervals[i][0];
                lEnd = intervals[i][1];
            }
        }
        ans.push_back(vector<int>{lStart, lEnd});
        return ans;
    }
};